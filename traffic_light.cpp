// traffic_light.cpp

#include "traffic_light.h"
#include <QWidget>
#include <QLayout>
#include <QRadioButton>

TrafficLight::TrafficLight(QWidget * parent): QWidget(parent) {

  // Add the red traffic light
  redlight = new QRadioButton;
  redlight->setEnabled(false);
  redlight->toggle();   // initialize the red light to be ON
  redlight->setStyleSheet("QRadioButton::indicator:checked { background-color: red;}");
  
    yellowlight = new QRadioButton;
    yellowlight->setEnabled(false);
    yellowlight->setStyleSheet("QRadioButton::indicator:checked { background-color: yellow;}");
      
    greenlight = new QRadioButton;
    greenlight->setEnabled(false);
    greenlight->setStyleSheet("QRadioButton::indicator:checked { background-color: green;}");
    
    auto layout = new QVBoxLayout;
    layout->addWidget(redlight);
    layout->addWidget(yellowlight);
    layout->addWidget(greenlight);

    setLayout(layout);

    light_state = RED;
}


// TO DO: build the light_update() slot function here
void TrafficLight::light_update()
{
    switch (light_state) {
    case RED:
        greenlight->toggle();
        light_state = GREEN;
        break;

    case GREEN:
        yellowlight->toggle();
        light_state = YELLOW;
        break;

    case YELLOW:
        redlight->toggle();
        light_state = RED;
        break;
    }
}