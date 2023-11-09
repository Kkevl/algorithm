#include"importer.h"
#include"alloccater.h"
int main(){
    
    importer loater;
    loater.getnumarray("../prog1_resource/12.in"); // 0.65sec
    // loater.printarrays();
    cout<<"\n=================="<<endl;
    // loater.adjustdata(0);
    // loater.printarrays();
    loater.resultable();    
    return 0;
}