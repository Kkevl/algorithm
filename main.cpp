#include"importer.h"
#include"alloccater.h"
int main(){
    
    importer loater;
    loater.getnumarray("../prog1_resource/500.in"); // 0.65sec at 5000
    // loater.printarrays();
    cout<<"=================="<<endl;
    // loater.adjustdata(0);
    loater.resultable();    
    return 0;
}