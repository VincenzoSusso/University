package esercizio1;

public class Rettangolo extends FiguraComp {

    //------------------------------------------
    public Rettangolo(double base, double height)
    {
        super(base, height);
    }

    public double area()
    {
        return this.getDim1() * this.getDim2();
    }

    public String toString()
    {
        return ("Base: " + super.getDim1() + "\n" + "Height: " + super.getDim2());
    }
}
