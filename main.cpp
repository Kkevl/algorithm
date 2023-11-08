#include"importer.h"
#include"alloccater.h"
int main(){
    
    importer loater;
    loater.getnumarray("../prog1_resource/500.in");
    loater.printarrays();
    cout<<"\n=================="<<endl;
    loater.adjustdata(0);
    loater.printarrays();
    cout<<endl;
    loater.resultable();
    return 0;
}