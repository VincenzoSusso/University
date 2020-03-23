package esercizio1;

public class Triangolo extends FiguraComp {

    //------------------------------------------
    public Triangolo(double base, double height)
    {
        super(base, height);
    }

    public double area()
    {
        return ((this.getDim1() * this.getDim2()) / 2);
    }

    public String toString()
    {
        return ("Base: " + super.getDim1() + "\n" + "Height: " + super.getDim2());
    }
}
