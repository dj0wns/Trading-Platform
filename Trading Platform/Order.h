#ifndef ORDER_H
#define ORDER_H
//Object to contain and execute an order
class Order
{
    public:
        Order(); //instantiate variables
        bool executeTrade();
    protected:
    private:
        bool *strategy();
        float time; //time for trade to execute
        float delta; // range the price is allowed to move before a stop
        int orders; //amount of buy/sell orders to execute

};

#endif // ORDER_H
