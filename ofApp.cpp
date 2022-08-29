#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(228,149,54);

	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	int size = 30;

	for (int x = size * -10; x <= size * 10; x += size) {

		for (int y = size * -10; y <= size * 10; y += size) {

			ofPushMatrix();
			ofTranslate(x, y);

			glm::vec2 param = glm::vec2(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005), ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005));

			int start_x = param.x < 0.48 ? size * -0.5 : param.x > 0.52 ? 0 : ofMap(param.x, 0.48, 0.52, size * -0.5, 0);
			int start_y = param.y < 0.48 ? size * -0.5 : param.y > 0.52 ? 0 : ofMap(param.y, 0.48, 0.52, size * -0.5, 0);

			ofSetColor(230);

			ofDrawLine(start_x, 0, start_x + size * 0.5, 0);
			ofDrawLine(0, start_y, 0, start_y + size * 0.5);

			ofSetColor(125);

			if (param.x < 0.48 && param.y < 0.48) {

				ofTranslate(size * -0.5, size * -0.5);

				ofBeginShape();
				for (int deg = 0; deg < 90; deg += 1) {

					ofVertex(size * 0.2 * cos(deg * DEG_TO_RAD), size * 0.2 * sin(deg * DEG_TO_RAD));
				}
				ofVertex(0, 0);
				ofEndShape(true);
			}

			if (param.x > 0.52 && param.y < 0.48) {

				ofTranslate(size * 0.5, size * -0.5);

				ofBeginShape();
				for (int deg = 90; deg < 180; deg += 1) {

					ofVertex(size * 0.2 * cos(deg * DEG_TO_RAD), size * 0.2 * sin(deg * DEG_TO_RAD));
				}
				ofVertex(0, 0);
				ofEndShape(true);
			}

			if (param.x > 0.52 && param.y > 0.52) {

				ofTranslate(size * 0.5, size * 0.5);

				ofBeginShape();
				for (int deg = 180; deg < 270; deg += 1) {

					ofVertex(size * 0.2 * cos(deg * DEG_TO_RAD), size * 0.2 * sin(deg * DEG_TO_RAD));
				}
				ofVertex(0, 0);
				ofEndShape(true);
			}

			if (param.x < 0.48 && param.y > 0.52) {

				ofTranslate(size * -0.5, size * 0.5);

				ofBeginShape();
				for (int deg = 270; deg < 360; deg += 1) {

					ofVertex(size * 0.2 * cos(deg * DEG_TO_RAD), size * 0.2 * sin(deg * DEG_TO_RAD));
				}
				ofVertex(0, 0);
				ofEndShape(true);
			}

			ofPopMatrix();
		}
	}
	
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}