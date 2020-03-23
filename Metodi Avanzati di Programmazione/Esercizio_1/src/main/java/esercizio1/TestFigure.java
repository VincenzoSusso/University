package esercizio1;

public class TestFigure {
    public static void main(String[] args) {
        FiguraComp rectangle = new Rettangolo(5.0, 3.0);
        FiguraComp triangle = new Triangolo(10.0, 5.0);
        FiguraComp square = new Quadrato(15.5);

        System.out.println("Rectangle");
        System.out.println(rectangle.toString());
        System.out.println("Area of Rectangle: " + rectangle.area());
        System.out.println("------------------------------------------");

        System.out.println("Triangle");
        System.out.println(triangle.toString());
        System.out.println("Area of Triangle: " + triangle.area());
        System.out.println("------------------------------------------");

        System.out.println("Square");
        System.out.println(square.toString());
        System.out.println("Area of Square: " + square.area());
        System.out.println("------------------------------------------");

        System.out.println("Triangle equals to Rectangle: " + triangle.compareTo(rectangle));

    }
}
