#include<iostream>
#include<fstream>
#include<string>
#include<hash_map>
#include <unordered_map>
using namespace std;

#define d1 0
#define d2 2

int main() {
    unordered_map<char,int> htoi;
    htoi.insert(make_pair('0',0));
    htoi.insert(make_pair('1',1));
    htoi.insert(make_pair('2',2));
    htoi.insert(make_pair('3',3));
    htoi.insert(make_pair('4',4));
    htoi.insert(make_pair('5',5));
    htoi.insert(make_pair('6',6));
    htoi.insert(make_pair('7',7));
    htoi.insert(make_pair('8',8));
    htoi.insert(make_pair('9',9));
    htoi.insert(make_pair('A',10));
    htoi.insert(make_pair('B',11));
    htoi.insert(make_pair('C',12));
    htoi.insert(make_pair('D',13));
    htoi.insert(make_pair('E',14));
    htoi.insert(make_pair('F',15));

    ifstream ifs;
    fstream ofs1;
    fstream ofs2;
    ofs1.open("C:/Users/18867/Desktop/wb/tools/data/car2/fault/53-acc.txt",ios::out );
    ofs2.open("C:/Users/18867/Desktop/wb/tools/data/car2/fault/53-adc.txt",ios::out );
     ifs.open("C:/Users/18867/Desktop/wb/tools/data/car2/fault/53.txt", ios::in);
    char buf1,buf2,buf3,buf4,buf5,buf6,buf7,buf8,buf9,buf10,buf11,buf12,buf13,buf14,buf15,buf16,buf17,buf18,buf19,buf20,buf21,buf22,buf23,buf24;
    ifs >> buf1;ifs >> buf2;ifs >> buf3;ifs >> buf4;ifs >> buf5;ifs >> buf6;ifs >> buf7;ifs >> buf8;
    if(buf1=='1'&&buf2=='2'&&buf3=='3'&&buf4=='4'&&buf5=='5'&&buf6=='6'&&buf7=='7'&&buf8=='8')
    while (ifs >> buf1&&ifs >> buf2&&ifs >> buf3&&ifs >> buf4&&ifs >> buf5&&ifs >> buf6&&ifs >> buf7&&ifs >> buf8&&ifs >> buf9&&ifs >> buf10&&ifs >> buf11&&ifs >> buf12&&ifs >> buf13&&ifs >> buf14&&ifs >> buf15&&ifs >> buf16&&ifs >> buf17&&ifs >> buf18&&ifs >> buf19&&ifs >> buf20&&ifs >> buf21&&ifs >> buf22&&ifs >> buf23&&ifs >> buf24)
    {
        int acc1,acc2,acc3,acc4,acc5,acc6,acc7,acc8,acc9;
        acc1=htoi[buf1]*16+htoi[buf2];
        acc2=htoi[buf3]*16+htoi[buf4];
        acc3=htoi[buf5]*16+htoi[buf6];
        acc4=htoi[buf7]*16+htoi[buf8];
        acc7=htoi[buf9]*16+htoi[buf10];
        acc8=htoi[buf11]*16+htoi[buf12];
        acc5=acc2&0x10;
        acc2=acc2&0x0f;
        acc6=acc4&0x10;
        acc4=acc4&0x0f;
        acc9=acc8&0x10;
        acc8=acc8&0x0f;
        if(acc5==16){
            acc2= (acc2-15)*256-(255-acc1);
        }else{
            acc2= acc2*256+acc1;
        }
        if(acc6==16){
            acc4= (-1)*(15-acc4)*256-(255-acc3);
        }else{
            acc4= acc4*256+acc3;
        }
        if(acc9==16){
            acc8= (-1)*(15-acc8)*256-(255-acc7);
        }else{
            acc8= acc8*256+acc7;
        }
        ofs1 <<acc2<<' '<<acc4<<' '<<acc8<<endl;
        int mic1,mic2,mic3,mic4;
        mic1=htoi[buf13]*4096+htoi[buf14]*256+htoi[buf15]*16+htoi[buf16];
        mic2=htoi[buf17]*4096+htoi[buf18]*256+htoi[buf19]*16+htoi[buf20];
        mic3=htoi[buf21]*4096+htoi[buf22]*256+htoi[buf23]*16+htoi[buf24];
        ofs2 <<mic1<<' '<<mic2<<' '<<mic3<<endl;
    }
    /*while (ifs >> buf1&&ifs >> buf2&&ifs >> buf3&&ifs >> buf4&&ifs >> buf5&&ifs >> buf6&&ifs >> buf7&&ifs >> buf8)
    {
        if(buf1=='1'&&buf2=='2'&&buf3=='3'&&buf4=='4'&&buf5=='5'&&buf6=='6'&&buf7=='7'&&buf8=='8') break;
        int mic1,mic2,mic3,mic4;
        mic1=htoi[buf1]*16+htoi[buf2];
        mic2=htoi[buf3]*16+htoi[buf4];
        mic3=htoi[buf5]*16+htoi[buf6];
        mic4=htoi[buf7]*16+htoi[buf8];
        if(mic1>8) mic2= (-1)*mic2;
        if(mic3>8) mic4= (-1)*mic4;
        ofs1 <<mic2<<' '<<mic4<<endl;
    }
    while (ifs >> buf1&&ifs >> buf2&&ifs >> buf3&&ifs >> buf4&&ifs >> buf5&&ifs >> buf6)
    {
        int mic1,mic2,mic3;
        mic1=htoi[buf1]*16+htoi[buf2];
        mic2=htoi[buf3]*16+htoi[buf4];
        mic3=htoi[buf5]*16+htoi[buf6];
        ofs2 <<mic1<<' '<<mic2<<' '<<mic3<<endl;
    }*/
    std::cout << "Hello, World!" << std::endl;
    ifs.close();
    ofs1.close();
    ofs2.close();
    return 0;
}
