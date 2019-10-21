Esercitazione 4:

Realizzare in C++ e testare in un main la struttura dati MyPoint:
    class MyPoint {
        public:
            MyPoint();
            MyPoint(int, int);
            int getX();
            int getY();
            void setX(int);
            void setY(int);
            double distance(MyPoint); // restituisce la distanza con un altro punto
            string toString(); // visualizza le coordinate del punto del tipo "MyPoint(x,y)"
        private:
            double x;
            double y;
    };

Realizzare in C++ e testare in un main la struttura dati MyCircle:
    class MyCircle{
        public:
            MyCircle();
            MyCircle(MyPoint, double);
            double getRadius();
            void setRadius(double);
            MyPoint getCenter();
            void setCenter(MyPoint);
            string toString(); // visualizza le informazioni sul cerchio tipo "MyCircle(radius=r,center=(x,y))"
            double getArea();
            double getCircumference();
            double distance(MyCircle); // restituisce la distanza dal centro al centro di un altro cerchio
        private:
            MyPoint center;
            double radius;
    };

Realizzare in C++ e testare in un main la struttura dati MyTriangle:
    class MyCircle{
        public:
            MyTriangle(MyPoint, MyPoint, MyPoint);
            string toString(); // visualizza le informazioni sul triangolo tipo "MyTriangle(v1=(x,y),v2=(x,y),v3=(x,y))"
            double getArea();
            double getPerimeter();
            string getType(); // restituisce "Equilatero", "Isoscele" o "Scaleno"
        private:
            MyPoint v1;
            MyPoint v2;
            MyPoint v3;
    };