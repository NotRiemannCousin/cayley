# Cayley
## C++ Linear Algebra Library

Cayley is a simple linear algebra implementation in C++23 for machine learning purposes.


One of the reasons that led me to this project was because I felt a desire to update my C++ skills using modern features like modules, format, concepts and other things from C++20-23. That's why, unlike Tensorflow, Tensors here are statically shaped (i.e. the shaped is defined by using templates at compile time and cannot be changed when running at runtime). Although less flexible, this approach can avoid some bugs like format mismatch, invalid operations in certain dimensions and optimization problems (which will ultimately be skill problems on my part).

In the future, when I have more experience, I will make another repository called Cauchy, exploring the dynamic format approach.