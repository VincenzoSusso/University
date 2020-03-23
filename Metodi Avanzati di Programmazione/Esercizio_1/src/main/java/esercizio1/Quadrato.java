package esercizio1;

public class Quadrato extends Rettangolo{
    //------------------------------------------
    public Quadrato(double side)
    {
        super(side, side);
    }

    public String toString()
    {
        return ("Side: " + super.getDim1());
    }
}
