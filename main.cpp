#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;
// Make image for Rorschach's test!
// SVG for Inkscape.
// https://fr.wikipedia.org/wiki/Inkscape (freeware GNU for almost all systems).
// https://fr.wikipedia.org/wiki/Scalable_Vector_Graphics (Universal ASCII vectorial format).



void help() {
    cout << "File must be writable!" << endl;
    }

int main() {
    srand ( time ( NULL ) ); // No need for better init.
int XMax = 1920;
int YMax = 1080;
    int X = 0;
    int Y = 0;
    int R = 0;
    int RX = 0;
    int RY = 0;
    int SX = 0;
    int SY = 0;
    int rot = 0;
    int colorRpc = 0;
    int colorVpc = 0;
    int colorBpc = 0;
    int opacity = 0;
 // int background = 256;
    int maxCercles = 420;
    int maxEllipses = 420;
    int maxItems = 1;
    string file = "Rorschach.svg"; // PPM, PNG, ORA are possible, too.
    ofstream myfile;
    // myfile.open (argv[1]);
    myfile.open (file);
    if (!myfile.is_open()) { // Error file.
        cerr << "Unable to write the file " << file << "!" << endl;   // Err of file? Help needed:
        help();
        return 2; // Error file.
        }
    else { // File ok.
        myfile << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"";
        myfile << XMax << "\" height=\"" << YMax << "\">" << endl;
        myfile << "<title>Image done by a procedural generator for Rorschach's tests.</title>\n<desc>Symetrical image.</desc>" << endl;

        for (int items=0; items<maxCercles ; items++) {
            X = (rand() % (XMax/2)) -2;
            Y = 2 + rand() % (YMax - 3);
            R = 2 + (rand() % 42);
            int colorRpc = rand() % 100;
            int colorVpc = rand() % 100;
            int colorBpc = rand() % 100;
            int opacity = rand() % 100;
            myfile << "<circle cx=\"" << X + (XMax/2) << "\" cy=\"" << Y << "\" r=\"" << R << "\" fill=\"rgb(" << colorRpc << "%, " << colorVpc << "%, " << colorBpc << "%)\" opacity=\"." << opacity << "\" /> ";
            myfile << "<circle cx=\"" << (XMax/2) - X << "\" cy=\"" << Y << "\" r=\"" << R << "\" fill=\"rgb(" << colorRpc << "%, " << colorVpc << "%, " << colorBpc << "%)\" opacity=\"." << opacity << "\" />\n";
            }
            myfile << "\n";

            for (int items=0; items<maxEllipses ; items++) {
            X = (rand() % (XMax/2)) -2;
            Y = 2 + rand() % (YMax - 3);
            RX = 2 + (rand() % 42);
            RY = 2 + (rand() % 42);
            SX = -85 + (rand() % 170);
            SY = -85 + (rand() % 170);
            rot = (rand() % 360);
            int colorRpc = rand() % 100;
            int colorVpc = rand() % 100;
            int colorBpc = rand() % 100;
            int opacity = rand() % 100;
     // Cisaillement avec décallage !
       //     myfile << "<ellipse cx=\"" << X + (XMax/2) << "\" cy=\"" << Y << "\" rx=\"" << RX << "\" ry=\"" << RY << "\" transform=\"skewX(" << SX <<")\" fill=\"rgb(" << colorRpc << "%, " << colorVpc << "%, " << colorBpc << "%)\" opacity=\"." << opacity << "\" /> ";
        //    myfile << "<ellipse cx=\"" << (XMax/2) - X << "\" cy=\"" << Y << "\" rx=\"" << RX << "\" ry=\"" << RY << "\" fill=\"rgb(" << colorRpc << "%, " << colorVpc << "%, " << colorBpc << "%)\" opacity=\"." << opacity << "\" />\n";
            myfile << "<ellipse cx=\"" << X + (XMax/2) << "\" cy=\"" << Y << "\" rx=\"" << RX << "\" ry=\"" << RY << "\" transform=\"rotate("<<   rot << ","<< (XMax/2) << "," << Y <<")\" fill=\"rgb(" << colorRpc << "%, " << colorVpc << "%, " << colorBpc << "%)\" opacity=\"." << opacity << "\" /> ";
            myfile << "<ellipse cx=\"" << (XMax/2) - X << "\" cy=\"" << Y << "\" rx=\"" << RX << "\" ry=\"" << RY << "\" transform=\"rotate("<<  -rot << ","<<(XMax/2) << "," << Y << ")\" fill=\"rgb(" << colorRpc << "%, " << colorVpc << "%, " << colorBpc << "%)\" opacity=\"." << opacity << "\" />\n";

            }
             myfile << "\n";
        for (int items=0; items<maxItems ; items++) {
            //  myfile << "<path ";
            }
             myfile << "\n";

        myfile << "\n</svg>";
        myfile.close();
        }
    cout << file << " is OK!" << endl;
    return 0;
    }
