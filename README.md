<p align="center">
  <img src="images/university_of_texas_at_el_paso_logo.png" width=250 />
</p>

# **Microprocessor-2-Lab-Template :zap:**

<div align="center">

[![Doxygen Action](https://github.com/jminjares4/Microprocessor-2-Lab-Template/actions/workflows/main.yml/badge.svg?branch=main)](https://github.com/jminjares4/Microprocessor-2-Lab-Template/actions/workflows/main.yml)
[![pages-build-deployment](https://github.com/jminjares4/Microprocessor-2-Lab-Template/actions/workflows/pages/pages-build-deployment/badge.svg)](https://github.com/jminjares4/Microprocessor-2-Lab-Template/actions/workflows/pages/pages-build-deployment)
[![GitHub Page](https://img.shields.io/badge/active-34c855.svg?style=flat&logo=github&logoColor=949da5&label=GitHub%20Page&labelColor=3f4851)](https://jminjares4.github.io/Microprocessor-2-Lab-Template)

</div>


## **Objective**
The objective of these labs is to provide more interactive tasks for students to be engaged in Microprocessor 2. Some labs will be reused from the previous semester but with better documentation.

## **Setup**
* Students must have an `ESP32`
* Install either `Visual Studio Code` or `Eclipse` 
## **Installation**
* Window's Linux Subsystem, MacOS, or Linux
  * Use the following link to install all the dependencies in the terminal and follow the guide: [ESP32 Installation](https://github.com/jminjares4/ESP32_Installation)
* Window 
  * Link to install ESP-IDF Windows Installer: [Window Installer](https://dl.espressif.com/dl/esp-idf/?idf=4.4)

## **Submodules**

```bash
git submodule update --init --recursive
```

## **Labs**
- [Lab 0 Lightshow](https://github.com/jminjares4/Microprocessor-2-Lab-Template/tree/main/Lab_0)
- [Lab 1 LED Controller with Inputs](https://github.com/jminjares4/Microprocessor-2-Lab-Template/tree/main/Lab_1)
- [Lab 2 Interrupts: Fire Alarm!](https://github.com/jminjares4/Microprocessor-2-Lab-Template/tree/main/Lab_2)
- [Lab 3 Introduction to FreeRTOS](https://github.com/jminjares4/Microprocessor-2-Lab-Template/tree/main/Lab_3) 
- [Lab 4 FreeRTOS: Semaphores](https://github.com/jminjares4/Microprocessor-2-Lab-Template/tree/main/Lab_4)
- [Lab 5 FreeRTOS: Queue](https://github.com/jminjares4/Microprocessor-2-Lab-Template/tree/main/Lab_5)
- [Lab 6 GPIO, Interrupts, and Queues](https://github.com/jminjares4/Microprocessor-2-Lab-Template/tree/main/Lab_6)
- [Lab 7 Peripheral and Queues: ADC and PWM (LEDC)](https://github.com/jminjares4/Microprocessor-2-Lab-Template/tree/main/Lab_7)
- [Lab 8 DAC Peripheral](https://github.com/jminjares4/Microprocessor-2-Lab-Template/tree/main/Lab_8)
- [Additional Labs](https://github.com/jminjares4/Microprocessor-2-Lab-Template/tree/main/Additional_Labs)
  - [Lab 9 WiFi and Internet of Things (IOT)](https://github.com/jminjares4/Microprocessor-2-Lab-Template/tree/main/Additional_Labs/Lab_9)
  - [Lab 10 WiFi and Internet of Things (IOT): Servo Motor Control](https://github.com/jminjares4/Microprocessor-2-Lab-Template/tree/main/Additional_Labs/Lab_10)
  - [Lab 11 WiFi and Internet of Things (IOT): ADC Monitor](https://github.com/jminjares4/Microprocessor-2-Lab-Template/tree/main/Additional_Labs/Lab_11)
  - [Lab 12 UART and LEDC (PWM)](https://github.com/jminjares4/Microprocessor-2-Lab-Template/tree/main/Additional_Labs/Lab_12)
  - [Lab 13 Assignment of Task to Cores](https://github.com/jminjares4/Microprocessor-2-Lab-Template/tree/main/Additional_Labs/Lab_13)
  - [Lab 14 ADC with LCD](https://github.com/jminjares4/Microprocessor-2-Lab-Template/tree/main/Additional_Labs/Lab_14)
  - [Adding_ESP_station_Demo](https://github.com/JosGranados/Microprocessor-2-Lab-Template/tree/main/Additional_Labs/Adding_ESP_station_Demo)


## **Development**
|Microcontroller|Software|Enviroment|Operating System|
| :---| :---| :---| :---|
| ![ESP32](https://img.shields.io/static/v1?label=&logo=espressif&message=Espressif+ESP32&&color=000000) | ![C Language](https://img.shields.io/badge/Code-C-informational?style=flat&logo=C&color=003B57)| ![Visual Studio Code](https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=flat&logo=visual%20studio%20code&logoColor=white&logoHeight=50&logoWidht=50) | ![FreeRTOS](https://img.shields.io/static/v1?label=OS&message=FreeRTOS&color=white&labelColor=green&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADAAAAAwCAMAAABg3Am1AAABLFBMVEUAAAA3Nzc4ODg6Ojo7OzsRERESEhITExMgICBFRUVHR0cMDAwNDQ0ODg4LCwsPDw8ZGRkUFBQVFRUJCQkKCgoLCwsUFBQNDQ0TExMKCgoICAgKCgoICAgKCgoLCwsGBgYGBgYHBwcICAgICAgJCQkICAgFBQUHBwcFBQUHBwcFBQUGBgYFBQUEBAQEBAQEBAQDAwMDAwMEBAQDAwMDAwMDAwMDAwMCAgIDAwMCAgIDAwMCAgICAgICAgIDAwMCAgIDAwMCAgICAgIDAwMCAgICAgIBAQEBAQECAgIBAQEBAQECAgIBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEBAQEAAAABAQEAAAAAAAABAQEAAAAAAAAAAAABAQEAAAAAAAAAAAAAAADpWFtfAAAAY3RSTlMAAgICAgQEBAQEBAgICAoKCgwMDg4ODhAQFBYWGBgYGhwcHiAgIiYmKCosMDg8QkRKTExSVFZcXl5gYGJmampubnR4en6PlZeXnaWlra%2Bztbe7vcHDz9Pb293f4fHz9fX3%2Bf1wHG5lAAACEklEQVR42pXWhWKjWhgE4Km7u7u7u7u3cSU08%2F7PcO%2Fuz8HJEr5KdHDmHPjMHj%2FG8yWylI8%2FHs8ixOhNki7Jm1FUNv2sk9rX7fbScEvr8NL27ZdG6k8zCNZ%2Br5Pf%2B11w6Nr7JvX7dgRYTZHvqwHvv5OpgPf3NWY3EWgzS20fHtfkWz8q6Hsjr33fv6tBRfV3nsQ%2BeYl%2FuiT3Hful8Q4h7qgZe06iPcW3OjgN6CTdZ7n%2Bjal2Fbhntg8uxyR5A5f%2BLO%2BNwIzOTZgm%2Fv5rTJJkrlO9oWxSn5HAE99h2v2N7QyufFD8rPVufZYPYXrnkwR0rtrfp4%2BdWKU%2BCpD8hjKkM0B5Dso3bwAqaqUBEjDtMekJbDDAnn3tapyFS3OZfhOwfPEYLgs06C9nR49FGtZhueUjnBreKdKLcv8lKWJtMG0zDtvIeYridxliqkCRuRqHYYl52ApUXqE8UCn3QAyzBJtG5QLKAU2DEK0kyNaqA6LE4ao3SeS5VPVOizi3qz6s4pG3gSfuxH%2FiDMf8Crk0xuAyS03KMeziowIkjXfCLm87cBN6A81D%2BZbAaJRblATgKYHtnpV3itha96a7BJ4l4KqZyb%2F%2FmirVzLQE%2FhZZf3iR9f0tMglIVdaHVWWdVCUZuYyj1709oNSjolpjQIk%2BZEUfFKMPu%2F6BfS9oYO9AsJkna%2BrQ2hI%2BdYg%2BOfFPf05n4fU%2FmeU4udThUscAAAAASUVORK5CYII%3D)|

## **License and Release**

| **License** | **Release** |
| :---    | :---    |
| [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT) |  [![Release](https://img.shields.io/github/v/release/jminjares4/Microprocessor-2-Lab-Template)](https://github.com/jminjares4/Microprocessor-2-Lab-Template/releases)        |

### **Authors**
* [**Jesus Minjares**](https://github.com/jminjares4)
  * **Master of Science in Computer Engineering** <br>
    [![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white&style=flat)](https://www.linkedin.com/in/jesusminjares/) [![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white&style=flat)](https://github.com/jminjares4)
* [**Erick Baca**](https://github.com/eabaca2419)
  * **Master of Science in Computer Engineering** <br>
    [![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white&style=flat)](https://www.linkedin.com/in/erick-baca/) [![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white&style=flat)](https://github.com/eabaca2419)
