int main()
{
    list <locuinta*> agentie;
    locuinta **v;
    int n;
    cout<<"Dati nr de obiecte:";
    cin>>n;
    v=new locuinta*[n];
    for(int i=0;i<n;)
        tip(v[i],i,agentie);


    list<locuinta*>::iterator i;
    cout<<"--------------------------\n";

    for(i=agentie.begin(); i!=agentie.end(); i++)
    {
        cout<<(**i);
        cout<<"----------------------------------------"<<endl;
    }

    return 0;
}
