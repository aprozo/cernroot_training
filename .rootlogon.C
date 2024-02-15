{
    // cout << "Loading .rootlogon.C" << endl;
    gSystem->Load("libRooUnfold");

    TStyle *myStyle = new TStyle("myStyle", "myStyle");
    myStyle->Reset("Modern");
    gStyle = myStyle;

    // Size & Margins
    myStyle->SetCanvasDefW(800);
    myStyle->SetCanvasDefH(600);

    // Basic object fill colors
    myStyle->SetCanvasBorderMode(0);
    myStyle->SetLegendFillColor(0);
    myStyle->SetCanvasColor(0);

    // Stat box
    myStyle->SetOptFit(112);
    myStyle->SetOptStat(10); // entries only //mean/rms should be replaced with a fit
    myStyle->SetStatFont(42);

    // Titles and Labels
    myStyle->SetLabelSize(0.05, "xyz");
    myStyle->SetTitleSize(0.055, "xyz");
    myStyle->SetTitleOffset(1.1, "x");
    myStyle->SetTitleOffset(0.8, "y");

    // Margins (correlated with title/label size)
    myStyle->SetPadBottomMargin(0.15);

    // Default Histogram Style Settings
    myStyle->SetHistFillColor(kTeal);
    myStyle->SetHistFillStyle(0); // solid fill (0 for hollow) //see http://root.cern.ch/root/html/TAttFill.html
    myStyle->SetHistLineColor(kBlack);
    myStyle->SetHistMinimumZero(kTRUE);
    myStyle->SetNdivisions(505);

    // Default Function Style Settings
    myStyle->SetFuncColor(kBlack);
    myStyle->SetFuncStyle(1); // see http://root.cern.ch/root/html/TAttLine.html
    myStyle->SetFuncWidth(3);

    // Default Line Style Settings
    myStyle->SetLineColor(kBlack);
    myStyle->SetLineStyle(1); // see http://root.cern.ch/root/html/TAttLine.html
    myStyle->SetLineWidth(1); // is border of TLegend

    // Default Graph Style Settings
    myStyle->SetMarkerColor(kBlack);
    myStyle->SetMarkerSize(1);   // see http://root.cern.ch/root/html/TAttMarker.html
    myStyle->SetMarkerStyle(22); // see http://root.cern.ch/root/html/TAttMarker.html

    // Grid
    // myStyle->SetPadGridX(kTRUE);
    // myStyle->SetPadGridY(kTRUE);

    // Histogram / Graph Title Size
    // myStyle->SetTitleSize(0.05, "t"); //"t": could be anything that is not "x" "y" or "z"
    // myStyle->SetTextSize(40);

    // myStyle->SetTextFont(43);

    // Palette
    myStyle->SetNumberContours(200);
#if ROOT_VERSION_CODE >= ROOT_VERSION(6, 0, 0)
    myStyle->SetPalette(kBird); // 57
#else
    myStyle->SetPalette(1, 0);
#endif

    TH1::SetDefaultSumw2();

    myStyle->SetStripDecimals(kFALSE);
    myStyle->SetTitleBorderSize(0);
    myStyle->SetTitleFillColor(0);
    //  myStyle->SetTitleAlign(6);

    myStyle->SetLegendBorderSize(0);
    myStyle->SetEndErrorSize(0);
    myStyle->SetErrorX(0.5);

    new TColor(2000, (255. / 255.), (89. / 255.), (74. / 255.));   // red-ish
    new TColor(2001, (25. / 255.), (170. / 255.), (25. / 255.));   // green-ish
    new TColor(2002, (66. / 255.), (98. / 255.), (255. / 255.));   // blue-ish
    new TColor(2003, (153. / 255.), (0. / 255.), (153. / 255.));   // magenta-ish
    new TColor(2004, (255. / 255.), (166. / 255.), (33. / 255.));  // yellow-ish
    new TColor(2005, (0. / 255.), (170. / 255.), (255. / 255.));   // azur-ish
    new TColor(2006, (204. / 255.), (153. / 255.), (255. / 255.)); // violet-ish
    new TColor(2007, (107. / 255.), (142. / 255.), (35. / 255.));  // olive
    new TColor(2008, (100. / 255.), (149. / 255.), (237. / 255.)); // corn flower blue
    new TColor(2009, (255. / 255.), (69. / 255.), (0. / 255.));    // orange red
    new TColor(2010, (0. / 255.), (128. / 255.), (128. / 255.));   // teal
    new TColor(2011, (176. / 255.), (196. / 255.), (222. / 255.)); // light steel blue
    new TColor(2012, (255. / 255.), (215. / 255.), (0. / 255.));   // gold-ish

    new TColor(3000, (251. / 255.), (228. / 255.), (216. / 255.));
    new TColor(3001, (223. / 255.), (182. / 255.), (178. / 255.));
    new TColor(3002, (133. / 255.), (79. / 255.), (108. / 255.));
    new TColor(3003, (82. / 255.), (43. / 255.), (91. / 255.));
    new TColor(3004, (43. / 255.), (18. / 255.), (76. / 255.));
    new TColor(3005, (25. / 255.), (0. / 255.), (25. / 255.));
    new TColor(3006, (49. / 255.), (61. / 255.), (90. / 255.));

    myStyle->cd();
}

TCanvas *MakeCanvas(const char *name, const char *title)
{
    // Start with a canvas
    TCanvas *canvas = new TCanvas(name, title);
    // General overall stuff
    canvas->SetFillColor(0);
    canvas->SetBorderMode(0);
    canvas->SetBorderSize(10);
    // Set margins to reasonable defaults
    canvas->SetLeftMargin(0.20);
    canvas->SetRightMargin(0.06);
    canvas->SetTopMargin(0.08);
    canvas->SetBottomMargin(0.15);
    // Setup a frame which makes sense
    canvas->SetFrameFillStyle(0);
    canvas->SetFrameLineStyle(0);
    canvas->SetFrameBorderMode(0);
    canvas->SetFrameBorderSize(10);
    canvas->SetFrameFillStyle(0);
    canvas->SetFrameLineStyle(0);
    canvas->SetFrameBorderMode(0);
    canvas->SetFrameBorderSize(10);

    return canvas;
}

void InitSubPad(TPad *pad, int i)
{
    // printf("Pad: %p, index: %d\n",pad,i);
    pad->cd(i);
    TPad *tmpPad = (TPad *)pad->GetPad(i);
    tmpPad->SetLeftMargin(0.20);
    tmpPad->SetTopMargin(0.06);
    tmpPad->SetRightMargin(0.08);
    tmpPad->SetBottomMargin(0.15);
    return;
}

void InitHist(TH1 *hist,
              const char *xtit,
              const char *ytit = "Number of Entries",
              EColor color = kBlack)
{
    hist->SetXTitle(xtit);
    hist->SetYTitle(ytit);
    hist->SetLineColor(color);
    hist->SetTitleSize(0.06, "X");
    hist->SetTitleSize(0.06, "Y");
    hist->SetTitleSize(0.06, "Z");
    hist->SetTitleOffset(3.800, "Y");
    hist->SetTitleOffset(3.800, "X");
    hist->SetTitleOffset(3.800, "Z");
    hist->SetLabelOffset(0.008, "Y");
    hist->SetLabelSize(0.050, "Y");
    hist->SetLabelFont(42, "Y");
    hist->SetMarkerStyle(20);
    hist->SetMarkerColor(color);
    hist->SetMarkerSize(0.6);
    // Strangely enough this cannot be set anywhere else??
    hist->GetYaxis()->SetTitleFont(42);
    hist->SetTitle("");
    return;
}

void fixedFontHist(TH1D *h, Float_t xoffset = 0.9, Float_t yoffset = 2.3)
{
    h->SetLabelFont(43, "X");
    h->SetLabelFont(43, "Y");
    // h->SetLabelOffset(0.01);
    h->SetLabelSize(16);
    h->SetTitleFont(43);
    h->SetTitleSize(20);
    h->SetLabelSize(15, "Y");
    h->SetTitleFont(43, "Y");
    h->SetTitleSize(17, "Y");
    h->SetTitleOffset(xoffset, "X");
    h->SetTitleOffset(yoffset, "Y");
    h->GetXaxis()->CenterTitle();
    h->GetYaxis()->CenterTitle();
}

void fixedFontHist(TH2D *h, Float_t xoffset = 0.9, Float_t yoffset = 2.3)
{
    h->SetLabelFont(43, "X");
    h->SetLabelFont(43, "Y");
    // h->SetLabelOffset(0.01);
    h->SetLabelSize(16);
    h->SetTitleFont(43);
    h->SetTitleSize(20);
    h->SetLabelSize(15, "Y");
    h->SetTitleFont(43, "Y");
    h->SetTitleSize(17, "Y");
    h->SetTitleOffset(xoffset, "X");
    h->SetTitleOffset(yoffset, "Y");
    h->GetXaxis()->CenterTitle();
    h->GetYaxis()->CenterTitle();
}
