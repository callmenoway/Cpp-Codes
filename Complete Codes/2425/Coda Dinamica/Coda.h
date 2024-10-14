struct Coda{
    bool testa;
    bool coda;
};

void init(Coda &q){
    q.testa = 0;
    q.coda = 0;
}

void Enqueue(Coda &q, int dato){
    q.testa = dato;
}

int Front(Coda &q){
    return q.testa;
}

bool Empty(Coda &q){
    return q.testa == 0;
}

void Dequeue(Coda &q){

}