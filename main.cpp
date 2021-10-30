#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;
// Make image for Rorschach's test!
// SVG for Inkscape.
// https://fr.wikipedia.org/wiki/Inkscape (freeware GNU for almost all systems).
// https://fr.wikipedia.org/wiki/Scalable_Vector_Graphics (Universal ASCII vectorial format).

int XMax = 1920;
int YMax = 1080;

void help() {
    cout << "File must be writable!" << endl;
    }

int main() {
    srand ( time ( NULL ) ); // No need for better init.
    int X = 0;
    int Y = 0;
    int R = 0;
    int colorRpc = 0;
    int colorVpc = 0;
    int colorBpc = 0;
 // int background = 256;
    int maxItems = 42;
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

        for (int items=0; items<maxItems ; items++) {
            X = (rand() % (XMax/2)) -2;
            Y = 2 + rand() % (YMax - 3);
            R = 5 + (rand() % 100);
            int colorRpc = rand() % 100;
            int colorVpc = rand() % 100;
            int colorBpc = rand() % 100;
            myfile << "<circle cx=\""<< X + (XMax/2) << "\" cy=\"" << Y << "\" r=\"" << R << "\" fill=\"rgb(" << colorRpc << "%, " << colorVpc << "%, " << colorBpc << "%)\" />";
            myfile << " <circle cx=\""<<  (XMax/2) - X<< "\" cy=\"" << Y << "\" r=\"" << R << "\" fill=\"rgb(" << colorRpc << "%, " << colorVpc << "%, " << colorBpc << "%)\" />\n";
            }
        for (int items=0; items<maxItems ; items++) {
            //  myfile << "<path ";
            } for (int items=0; items<maxItems ; items++) {
            //    myfile << "<ellipse";
            } for (int items=0; items<maxItems ; items++) {
            myfile << "";
            }
        myfile << "\n</svg>";
        myfile.close();
        }
    cout << file << " is OK!" << endl;
    return 0;
    }