//
//  pdfOutput.cpp
//  Timetabler
//
//  Created by Charles Baynham on 21/08/2013.
//  Copyright (c) 2013 Charles Baynham. All rights reserved.
//

#include "pdfOutput.h"

#include <Wt/WPushButton>
#include <Wt/WResource>
#include <Wt/Http/Request>
#include <Wt/Http/Response>
#include <Wt/Render/WPdfRenderer>
#include <Wt/WApplication>

#include "hpdf.h"

namespace {
    void error_handler(HPDF_STATUS error_no, HPDF_STATUS detail_no,
                       void *user_data) {
        fprintf(stderr, "libharu error: error_no=%04X, detail_no=%d\n",
                (unsigned int) error_no, (int) detail_no);
    }
}

class ReportResource : public Wt::WResource
{
public:
    ReportResource(Wt::WObject *parent = 0)
	: Wt::WResource(parent)
    {
        suggestFileName("report.pdf");
    }
    
    virtual void handleRequest(const Wt::Http::Request& request,
                               Wt::Http::Response& response)
    {
        response.setMimeType("application/pdf");
        
        HPDF_Doc pdf = HPDF_New(error_handler, 0);
        
        // Note: UTF-8 encoding (for TrueType fonts) is only available since libharu 2.3.0 !
        HPDF_UseUTFEncodings(pdf);
        
        renderReport(pdf);
        
        HPDF_SaveToStream(pdf);
        unsigned int size = HPDF_GetStreamSize(pdf);
        HPDF_BYTE *buf = new HPDF_BYTE[size];
        HPDF_ReadFromStream (pdf, buf, &size);
        HPDF_Free(pdf);
        response.out().write((char*)buf, size);
        delete[] buf;
    }
    
private:
    void renderReport(HPDF_Doc pdf) {
        renderPdf(Wt::WString::tr("report.example"), pdf);
    }
    
    void renderPdf(const Wt::WString& html, HPDF_Doc pdf)
    {
        HPDF_Page page = HPDF_AddPage(pdf);
        HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);
        
        Wt::Render::WPdfRenderer renderer(pdf, page);
        renderer.setMargin(2.54);
        renderer.setDpi(96);
        renderer.render(html);
    }
};

//Wt::WContainerWidget *container = new Wt::WContainerWidget();
//
//Wt::WText *text = new Wt::WText(Wt::WString::tr("report.example"), container);
//text->setStyleClass("reset");
//
//Wt::WPushButton *button = new Wt::WPushButton("Create pdf", container);
//
//Wt::WResource *pdf = new ReportResource(container);
//button->setLink(pdf);