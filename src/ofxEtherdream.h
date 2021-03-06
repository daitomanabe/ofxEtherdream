//
//  ofxEtherdream.h
//  ofxILDA
//
//  Created by Daito Manabe + Yusuke Tomoto (Rhizomatiks)
//  Mods by Memo Akten
//
//


#include "ofMain.h"
#include "etherdream.h"
#include "ofxIldaFrame.h"

class ofxEtherdream : public ofThread {
public:
    ofxEtherdream():state(ETHERDREAM_NOTFOUND) {}
    
    ~ofxEtherdream() {
        if(state == ETHERDREAM_FOUND) {
            etherdream_stop(device);
            etherdream_disconnect(device);
        }
    }
    
    void setup();
    virtual void threadedFunction();
    
    void clear();
    void start();
    void stop();
    
    void setPoints(const vector<ofxIlda::Point>& _points);
    void setPoints(const ofxIlda::Frame &ildaFrame);
    
    void setPPS(int i);
    int getPPS();
    
private:
    void init();
    
private:
    enum {
        ETHERDREAM_NOTFOUND = 0,
        ETHERDREAM_FOUND
    } state;
    
    int pps;
    
    struct etherdream *device;
    vector<ofxIlda::Point> points;
};