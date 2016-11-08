//
//  Particle.cpp
//  FirstParticleSystem
//
//  Created by Weili Shi on 11/3/16.
//
//

#include "Particle.hpp"

Particle::Particle(ofVec2f pos) {
    
    mPosition = pos;
    mVelocity = ofVec2f(ofRandom(-2.f, 2.f), ofRandom(-2.f, 2.f));
    mAcceleration = ofVec2f(0, 0);
    mLifeSpan = INITIAL_LIFE_SPAN;
    
}

void Particle::resetForces() {
    
    mAcceleration *= 0;
    
}

void Particle::applyForce(ofVec2f force) {
    
    mAcceleration += force;
    
}

void Particle::update(float multiplier) {
    
    // apply acceleration to velocity
    mVelocity += mAcceleration;
    mPosition += mVelocity * multiplier;
    
    // decrease the particle life
    if (mLifeSpan > 0) {
        mLifeSpan -= 1.0f;
    }
    
}

void Particle::draw() {
    
    if(mLifeSpan > BLINKING_LIFE_SPAN) {
        // new born particle will be brighter
        ofSetColor(255,163,247);
    } else {
        // do some sparkle!
        ofSetColor(ofRandom(0, mLifeSpan/INITIAL_LIFE_SPAN * 255),163,247);
    }
    
    
    ofDrawCircle(mPosition+ofVec2f(50,300), 20.0f * ofMap(mLifeSpan, 0, 255.f, 0, 1.f));
    
    
    if(mLifeSpan > BLINKING_LIFE_SPAN) {
        // new born particle will be brighter
        ofSetColor(255,163,0);
    } else {
        // do some sparkle!
        ofSetColor(ofRandom(0, mLifeSpan/INITIAL_LIFE_SPAN * 255),0,247);
    }

    ofDrawRectangle(mPosition, 20.0f * ofMap(mLifeSpan, 0, 255.f, 0, 1.f),7);
    
    
    if(mLifeSpan > BLINKING_LIFE_SPAN) {
        // new born particle will be brighter
        ofSetColor(255,23,201);
    } else {
        // do some sparkle!
        ofSetColor(ofRandom(0, mLifeSpan/INITIAL_LIFE_SPAN * 255),255,91);
    }

    float x2 = ofMap(mLifeSpan, 0, 160.f,0,630.f);
    float y2 = ofMap(mLifeSpan, 0, 160.f,0,410.f);
    
    float x3 = ofMap(mLifeSpan, 0, 160.f,0,700.f);
    float y3 = ofMap(mLifeSpan, 0, 160.f,0,420.f);
    
    ofDrawTriangle(mPosition+ofVec2f(300,200), mPosition+ofVec2f(x2,y2), mPosition+ofVec2f(x3,y3));
    
    
    
}
