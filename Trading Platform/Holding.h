//this class exists to hold detailed information about the positions currently held

#ifndef HOLDING_H
#define HOLDING_H


class Holding
{
    public:
        Holding();
    protected:
    private:
        int numberOwned; //number of positions owned, negative if short
        float pricePurchased; //price per unit purchased at, is an average
};

#endif // HOLDING_H
