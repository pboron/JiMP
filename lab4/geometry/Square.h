//
// Created by Student on 23.03.2017.
//

#ifndef JIMP_EXERCISES_SQUARE_H
#define JIMP_EXERCISES_SQUARE_H

namespace geometry{
    class Square{
    public:
        Square();
        Square(double Circumference, double Area);
        ~Square();

        double GetCircumference() const;
        double GetArea() const;

        void SetCircumference() const;
        void SetArea() const;

        double Circumference();

    private:
        double Circumference_, Area_;
    };
}

#endif //JIMP_EXERCISES_SQUARE_H
