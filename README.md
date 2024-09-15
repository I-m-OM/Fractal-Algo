# Fractal-Algo

This repository contains the implementation of an algorithm to calculate the **Fractal Dimension** of square images. The project plays a crucial role in studying **emotion recognition** by quantifying different human emotions and their intensities. 

## 🚀 Overview

The goal of this project is to compute the **Fractal Dimension** of square images and use it to quantify **7 human emotions**, along with their intensities (scale 1-6) and viewing angles (-45°, 0°, +45°). The primary application of this algorithm is to dive deep into **emotion recognition** research, potentially helping individuals with conditions like **Autism Spectrum Disorder (ASD)** in the future.

You can check the entire project and run the code from this Google Colab link:  
[![Open in Google Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/drive/14BnB0KYwzwwi0fQdyq1Eekzl2qOR9ubG?authuser=2#scrollTo=QMZTztww4eu2)

## 🛠️ Tech Stack

- **Languages:**  
  ![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
  ![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
  
  The above written algorithm by me was initially in C++, but we converted it to python to use it with other usefull libraries offered in python

- **Libraries/Tools:**  
  ![OpenCV](https://img.shields.io/badge/OpenCV-5C3EE8?style=for-the-badge&logo=opencv&logoColor=white)  
  ![Matplotlib](https://img.shields.io/badge/Matplotlib-3776AB?style=for-the-badge&logo=python&logoColor=white)  
  **Google Colab**

## 📊 Project Details

In this project, we compute the **Fractal Dimension** of NxN square images, aiming to study how the dimension correlates with different emotions. By analyzing various images from the **Indian Affective Picture Database (IAPD)** at **IIT Kanpur**, the algorithm provides insights into how different emotions, their intensities, and viewing angles affect the fractal dimension.

### Applications
- **Emotion Recognition:**  
  This algorithm quantifies 7 human emotions based on specific features in the images.
  
- **Autism Spectrum Disorder (ASD):**  
  In the future, we plan to apply this research in ASD studies, where emotion recognition plays a critical role in improving communication and behavioral therapy.

- **Machine Learning Integration:**  
  Future work aims to automate the process by training an AI/ML model using data from the IAPD to further refine the emotional analysis.

## ⚙️ How It Works

1. **Input:** Square NxN images from the IAPD, with various viewing angles (-45°, 0°, +45°).
2. **Fractal Dimension Calculation:** The algorithm computes the fractal dimension to quantify the emotional intensity of the image.
3. **Emotion Quantification:** The calculated fractal dimension is used to estimate the intensity (scale 1-6) of 7 distinct emotions captured in the image.

## 🚧 Future Improvements

- **Automating the Process:**  
  Plan to automate the fractal dimension analysis using **AI** and **Machine Learning**.
  
- **ML Model Training:**  
  Train models using IAPD images for more accurate emotion recognition.

- **ASD Applications:**  
  Contribute to the field of Autism Spectrum Disorder by using fractal dimension analysis to aid in emotion recognition studies and therapy.

## 📝 License

This project is licensed under the MIT License.

---

### 🔗 Google Colab Link

Check the full project and run the code in Google Colab:  
[![Open in Google Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/drive/14BnB0KYwzwwi0fQdyq1Eekzl2qOR9ubG?authuser=2)

---

Feel free to fork this repository or contribute to the project by submitting a pull request!
