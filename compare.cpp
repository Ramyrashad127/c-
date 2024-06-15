struct com {
    bool operator()(int x, int y) const{
        return x<y;
    }
};
// set and priority queue