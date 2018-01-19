//
//  main.cpp
//  drone_ analysis
//
//  Created by qiu on 09/01/2018.
//  Copyright © 2018 qiu. All rights reserved.
//
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>


typedef struct subj{
    uint id;
    
    std::string age;
    std::string gender;
    std::string dronex;
    
    std::string q[20];
    std::string comment;

} SubjectRecord;
typedef std::vector<SubjectRecord> SubjectRecordVec;

typedef struct subj2{
    uint id;
    uint age;
    std::string gender;
    uint dronex;
    
    int score[20];
    std::string comment;
} SubjectResult;


typedef std::vector<SubjectResult> SubjectResultVec;

std::string Trim(std::string& str){
    str.erase(0, str.find_first_not_of("\t\r\n"));
    str.erase(str.find_last_not_of("\t\r\n") + 1);
    return  str;
}
int readRecord(std::string filename, SubjectRecordVec *recordVec)
{
    SubjectRecord rectemp;
    recordVec->clear();
    
    int i = 0;
    std::ifstream fin;
    std::string line;
    fin.open(filename, std::ios::in);

    int j = 0;
    while (getline(fin, line)) {
        //to do

        std::istringstream sin(line);
        std::string field;
        if (line == "hahaha") {
            i++;
            j = 0;
            recordVec->push_back(rectemp);
        }
        else if(j == 4)
            {
                std::vector<std::string> infofields;
                while (getline(sin, field, '|')) {
                    infofields.push_back(field);
                }
                rectemp.age =Trim(infofields[0]);
                rectemp.gender =Trim(infofields[1]);
                rectemp.dronex =Trim(infofields[2]);
                j++;
            }
            else if(j == 5)
            {
                rectemp.comment = line;
            }
                else
            {
                std::vector<std::string> fields;
                while (getline(sin, field, '|')) {
                    fields.push_back(field);
                }
                rectemp.id = i + 1;
                
                rectemp.q[5*j] = Trim(fields[0]);
                rectemp.q[1+5*j] = Trim(fields[1]);
                rectemp.q[2+5*j] = Trim(fields[2]);
                rectemp.q[3+5*j] = Trim(fields[3]);
                rectemp.q[4+5*j] = Trim(fields[4]);
                //rectemp.comment[j] = Trim(fields[3]);
                j++;
            }

    }
    
    return i;
}

void printRecordVec(SubjectRecordVec recvec){
    for (std::vector<SubjectRecord>::const_iterator iter = recvec.cbegin(); iter != recvec.cend(); iter++)
    {
        std::cout <<"phased subject info:\n" << " age: " <<(*iter).age<< " gender: " <<(*iter).gender<< " id: " <<(*iter).id<< std::endl;
        std::cout << "answers:" <<std::endl;
        for (int i = 0; i < 20; i++) {
            std::cout<<"choice " <<i<<":"<<(*iter).q[i]<<std::endl;
        }
        std::cout<<"comment: "<<(*iter).comment<<std::endl;
        std::cout<<std::endl;
    }
    
}

void getResult(SubjectRecordVec recvec, SubjectResultVec *resvec){
    resvec->clear();
    SubjectResult tempres;
    for (std::vector<SubjectRecord>::const_iterator iter = recvec.cbegin(); iter != recvec.cend(); iter++)
    {
        //info
        tempres.id = iter->id;
        tempres.gender = iter->gender;
        tempres.age = (int)stoi(iter->age);
        tempres.dronex = (int)stoi(iter->dronex);
        //
        for (int i = 0; i < 20; i++) {
        std::istringstream phrase((*iter).q[i]);
            std::vector<std::string> fields_;
            std::string field;
            while (getline(phrase, field, '_')) {
                fields_.push_back(field);
            }
            std::string scene = Trim(fields_[0]);
            std::string nothing = Trim(fields_[1]);
            std::string flag = Trim(fields_[2]);
            std::string compare = Trim(fields_[3]);
            std::string score = Trim(fields_[4]);
            
            //std::cout << stoi(scene) << std::endl;
            //std::cout << stoi(nothing) << std::endl;
            //std::cout << stoi(flag) << std::endl;
            //std::cout << stoi(compare) << std::endl;
            //std::cout << stoi(score) << std::endl;
            int flag_ = stoi(flag);
            int compare_ = 1;
            int scene_ = stoi(scene);
            if (compare == "-") {
                compare_ = -1;
            }
            if (flag_ == 1) {
                flag_ = 1;
            }
            else if (flag_ == 2){
                flag_ = -1;
            }
            else{
                std::cout<<"data error"<<std::endl;
                exit(1);
            }
//            int iiii = 3*(scene_-1)+(i)%3;
//            int bbbb = compare_ * flag_ * (int)stoi(score);;
//            std::cout<<"iiii:"<<iiii<<std::endl;
//             std::cout<<"bbbb:"<<bbbb<<std::endl;
//
            tempres.score[5*(scene_-1)+(i)%5] = compare_ * flag_ * (int)stoi(score);
//            std::cout<<std::endl;
        }

//        for (int i = 0; i < 12; i++) {
//            std::cout<<tempres.score[i]<<std::endl;
//            }
        tempres.comment = iter->comment;
        resvec->push_back(tempres);
//        std::cout<<std::endl;
    }
    
    
    
}

void printResultVec(SubjectResultVec resvec){
    
    
    
    std::cout << "h!" <<std::endl;
}

void printComment(SubjectRecordVec recvec){
    
    
    
    std::cout << "hello comment" <<std::endl;
}

void analyseResultVecSigdrone(SubjectResultVec resvec){
    int num = resvec.size();
    double temp;
    std::cout<<"Scene 1: Seaworld auto VS GSP"<<std::endl;
    std::cout<<"\tscore 1:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {   temp+=iter->score[0];
        std::cout<< iter->score[0] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 2:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[1];
        std::cout<< iter->score[1] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 3:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[2];
        std::cout<< iter->score[2] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 4:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[3];
        std::cout<< iter->score[3] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 5:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[4];
        std::cout<< iter->score[4] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<std::endl;
    std::cout<<"Scene 2: University auto VS manu"<<std::endl;
    temp = 0;
    std::cout<<"\tscore 1:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[5];
        std::cout<< iter->score[5] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 2:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[6];
        std::cout<< iter->score[6] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 3:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[7];
        std::cout<< iter->score[7] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 4:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[8];
        std::cout<< iter->score[8] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 5:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[9];
        std::cout<< iter->score[9] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<std::endl;
    std::cout<<"Scene 3: Bay auto VS GSP"<<std::endl;
    temp = 0;
    std::cout<<"\tscore 1:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[10];
        std::cout<< iter->score[10] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 2:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[11];
        std::cout<< iter->score[11] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 3:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[12];
        std::cout<< iter->score[12] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 4:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[13];
        std::cout<< iter->score[13] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 5:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[14];
        std::cout<< iter->score[14] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<std::endl;
    std::cout<<"Scene 4: Beach auto VS manu"<<std::endl;
    temp = 0;
    std::cout<<"\tscore 1:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[15];
        std::cout<< iter->score[15] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 2:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[16];
        std::cout<< iter->score[16] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 3:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[17];
        std::cout<< iter->score[17] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 4:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[18];
        std::cout<< iter->score[18] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 5:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[19];
        std::cout<< iter->score[19] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    

}

void analyseResultVecDronesig(SubjectResultVec resvec){
    int num = resvec.size();
    double temp;
    std::cout<<"Scene 1: Seaworld auto VS manu"<<std::endl;
    std::cout<<"\tscore 1:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {   temp+=iter->score[0];
        std::cout<< iter->score[0] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 2:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[1];
        std::cout<< iter->score[1] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 3:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[2];
        std::cout<< iter->score[2] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 4:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[3];
        std::cout<< iter->score[3] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 5:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[4];
        std::cout<< iter->score[4] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<std::endl;
    std::cout<<"Scene 2: University auto VS GSP"<<std::endl;
    temp = 0;
    std::cout<<"\tscore 1:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[5];
        std::cout<< iter->score[5] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 2:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[6];
        std::cout<< iter->score[6] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 3:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[7];
        std::cout<< iter->score[7] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 4:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[8];
        std::cout<< iter->score[8] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 5:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[9];
        std::cout<< iter->score[9] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<std::endl;
    std::cout<<"Scene 3: Bay auto VS manu"<<std::endl;
    temp = 0;
    std::cout<<"\tscore 1:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[10];
        std::cout<< iter->score[10] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 2:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[11];
        std::cout<< iter->score[11] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 3:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[12];
        std::cout<< iter->score[12] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 4:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[13];
        std::cout<< iter->score[13] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 5:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[14];
        std::cout<< iter->score[14] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<std::endl;
    std::cout<<"Scene 4: Beach auto VS GSP"<<std::endl;
    temp = 0;
    std::cout<<"\tscore 1:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[15];
        std::cout<< iter->score[15] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 2:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[16];
        std::cout<< iter->score[16] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 3:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[17];
        std::cout<< iter->score[17] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 4:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[18];
        std::cout<< iter->score[18] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
    std::cout<<"\tscore 5:"<<std::endl;
    temp = 0;
    for (std::vector<SubjectResult>::const_iterator iter = resvec.cbegin(); iter != resvec.cend(); iter++)
    {
        temp+=iter->score[19];
        std::cout<< iter->score[19] <<"\t";
    }
    std::cout<<std::endl;
    std::cout<<"average:"<<temp/num;
    std::cout<<std::endl;
    
}

bool findSTR(std::string src, std::string d)
{
    std::string::size_type idx;
    
    idx=src.find(d);//在src中查找d.
    if(idx == std::string::npos )//不存在。
        return false;
    else//存在。
        return true;
}

std::string csvHandlerStr(std::string str) {
    //csv格式如果有逗号，整体用双引号括起来；如果里面还有双引号就替换成两个双引号，这样导出来的格式就不会有问题了
    std::string tempDescription = str;
    //如果有逗号
    if(findSTR(str, ",")){
//        //如果还有双引号，先将双引号转义，避免两边加了双引号后转义错误
//        if(findSTR(str,"\"")){
//            tempDescription=str.replace("\"", "\"\"");
//        }
        //在将逗号转义
        tempDescription="\""+tempDescription+"\"";
    }
    return tempDescription;
}

void saveCSV(SubjectResultVec resultsigdrone, SubjectResultVec resultdronesig){
    
    int questionNum = 5;
    //定义文件输出流
    std::ofstream oFile;
    
    uint num_sigdrone = resultsigdrone.size();
    uint num_dronesig = resultdronesig.size();
    std::cout << num_sigdrone <<std::endl;
    
    //score1
    oFile.open("/Users/qiu/PycharmProjects/drone/scoresheet1.csv", std::ios::out | std::ios::trunc);    // 这样就很容易的输出一个需要的excel 文件
    oFile << "id" << "," << "age" << "," << "gender" << "," << "expertise" <<  "," << "Seaworld_manu" <<  "," << "Seaworld_GSP" <<  "," << "University_manu" <<  "," << "University_GSP" <<  "," << "Bay_manu" << "," << "Bay_GSP" << "," <<"Beach_manu" << "," << "Beach_GSP" << "," << " comment" <<std::endl;
        //sigdrone
    for (std::vector<SubjectResult>::const_iterator iter = resultsigdrone.cbegin(); iter != resultsigdrone.cend(); iter++)
    {
        oFile << iter->id << "," << iter->age << "," << iter->gender << "," << iter->dronex <<  "," << "NULL" <<  "," << iter->score[0] <<  "," << iter->score[questionNum] <<  "," << "NULL" <<  "," << "NULL" << "," << iter->score[ 2 * questionNum] << "," << iter->score[3 * questionNum] << "," << "NULL" << "," << csvHandlerStr(iter->comment) <<std::endl;
    }
        //dronesig
    for (std::vector<SubjectResult>::const_iterator iter = resultdronesig.cbegin(); iter != resultdronesig.cend(); iter++)
    {
        oFile << iter->id + num_sigdrone << "," << iter->age << "," << iter->gender << "," << iter->dronex <<  "," << iter->score[0] <<  "," << "NULL" <<  "," << "NULL" <<  "," << iter->score[questionNum] <<  "," << iter->score[ 2 * questionNum] << "," << "NULL" << "," <<"NULL" << "," << iter->score[3 * questionNum] << "," << csvHandlerStr(iter->comment) <<std::endl;
    }
    oFile.close();
    
    //score2
    oFile.open("/Users/qiu/PycharmProjects/drone/scoresheet2.csv", std::ios::out | std::ios::trunc);    // 这样就很容易的输出一个需要的excel 文件
    oFile << "id" << "," << "age" << "," << "gender" << "," << "expertise" <<  "," << "Seaworld_manu" <<  "," << "Seaworld_GSP" <<  "," << "University_manu" <<  "," << "University_GSP" <<  "," << "Bay_manu" << "," << "Bay_GSP" << "," <<"Beach_manu" << "," << "Beach_GSP" << "," << " comment" <<std::endl;
    //sigdrone
    for (std::vector<SubjectResult>::const_iterator iter = resultsigdrone.cbegin(); iter != resultsigdrone.cend(); iter++)
    {
        oFile << iter->id << "," << iter->age << "," << iter->gender << "," << iter->dronex <<  "," << "NULL" <<  "," << iter->score[1] <<  "," << iter->score[1 + questionNum] <<  "," << "NULL" <<  "," << "NULL" << "," << iter->score[1+2*questionNum] << "," << iter->score[1 + 3*questionNum] << "," << "NULL" << "," << csvHandlerStr(iter->comment) <<std::endl;
    }
    //dronesig
    for (std::vector<SubjectResult>::const_iterator iter = resultdronesig.cbegin(); iter != resultdronesig.cend(); iter++)
    {
        oFile << iter->id + num_sigdrone << "," << iter->age << "," << iter->gender << "," << iter->dronex <<  "," << iter->score[1] <<  "," << "NULL" <<  "," << "NULL" <<  "," << iter->score[1+questionNum] <<  "," << iter->score[1+2*questionNum] << "," << "NULL" << "," <<"NULL" << "," << iter->score[1+3*questionNum] << "," << csvHandlerStr(iter->comment) <<std::endl;
    }
    oFile.close();
    
    //score3
    oFile.open("/Users/qiu/PycharmProjects/drone/scoresheet3.csv", std::ios::out | std::ios::trunc);    // 这样就很容易的输出一个需要的excel 文件
    oFile << "id" << "," << "age" << "," << "gender" << "," << "expertise" <<  "," << "Seaworld_manu" <<  "," << "Seaworld_GSP" <<  "," << "University_manu" <<  "," << "University_GSP" <<  "," << "Bay_manu" << "," << "Bay_GSP" << "," <<"Beach_manu" << "," << "Beach_GSP" << "," << " comment" <<std::endl;
    //sigdrone
    for (std::vector<SubjectResult>::const_iterator iter = resultsigdrone.cbegin(); iter != resultsigdrone.cend(); iter++)
    {
        oFile << iter->id << "," << iter->age << "," << iter->gender << "," << iter->dronex <<  "," << "NULL" <<  "," << iter->score[2] <<  "," << iter->score[2+questionNum] <<  "," << "NULL" <<  "," << "NULL" << "," << iter->score[2+ 2*questionNum] << "," << iter->score[2+3*questionNum] << "," << "NULL" << "," << csvHandlerStr(iter->comment) <<std::endl;
    }
    //dronesig
    for (std::vector<SubjectResult>::const_iterator iter = resultdronesig.cbegin(); iter != resultdronesig.cend(); iter++)
    {
        oFile << iter->id + num_sigdrone << "," << iter->age << "," << iter->gender << "," << iter->dronex <<  "," << iter->score[2] <<  "," << "NULL" <<  "," << "NULL" <<  "," << iter->score[2 + questionNum] <<  "," << iter->score[2+ 2*questionNum] << "," << "NULL" << "," <<"NULL" << "," << iter->score[2+3*questionNum] << "," << csvHandlerStr(iter->comment) <<std::endl;
    }
    oFile.close();
    //score4
    oFile.open("/Users/qiu/PycharmProjects/drone/scoresheet4.csv", std::ios::out | std::ios::trunc);    // 这样就很容易的输出一个需要的excel 文件
    oFile << "id" << "," << "age" << "," << "gender" << "," << "expertise" <<  "," << "Seaworld_manu" <<  "," << "Seaworld_GSP" <<  "," << "University_manu" <<  "," << "University_GSP" <<  "," << "Bay_manu" << "," << "Bay_GSP" << "," <<"Beach_manu" << "," << "Beach_GSP" << "," << " comment" <<std::endl;
    //sigdrone
    for (std::vector<SubjectResult>::const_iterator iter = resultsigdrone.cbegin(); iter != resultsigdrone.cend(); iter++)
    {
        oFile << iter->id << "," << iter->age << "," << iter->gender << "," << iter->dronex <<  "," << "NULL" <<  "," << iter->score[3] <<  "," << iter->score[3 + questionNum] <<  "," << "NULL" <<  "," << "NULL" << "," << iter->score[3+2*questionNum] << "," << iter->score[3+3*questionNum] << "," << "NULL" << "," << csvHandlerStr(iter->comment) <<std::endl;
    }
    //dronesig
    for (std::vector<SubjectResult>::const_iterator iter = resultdronesig.cbegin(); iter != resultdronesig.cend(); iter++)
    {
        oFile << iter->id + num_sigdrone << "," << iter->age << "," << iter->gender << "," << iter->dronex <<  "," << iter->score[3] <<  "," << "NULL" <<  "," << "NULL" <<  "," << iter->score[3+questionNum] <<  "," << iter->score[3+2*questionNum] << "," << "NULL" << "," <<"NULL" << "," << iter->score[3+3*questionNum] << "," << csvHandlerStr(iter->comment) <<std::endl;
    }
    oFile.close();
    //score5
    oFile.open("/Users/qiu/PycharmProjects/drone/scoresheet5.csv", std::ios::out | std::ios::trunc);    // 这样就很容易的输出一个需要的excel 文件
    oFile << "id" << "," << "age" << "," << "gender" << "," << "expertise" <<  "," << "Seaworld_manu" <<  "," << "Seaworld_GSP" <<  "," << "University_manu" <<  "," << "University_GSP" <<  "," << "Bay_manu" << "," << "Bay_GSP" << "," <<"Beach_manu" << "," << "Beach_GSP" << "," << " comment" <<std::endl;
    //sigdrone
    for (std::vector<SubjectResult>::const_iterator iter = resultsigdrone.cbegin(); iter != resultsigdrone.cend(); iter++)
    {
        oFile << iter->id << "," << iter->age << "," << iter->gender << "," << iter->dronex <<  "," << "NULL" <<  "," << iter->score[4] <<  "," << iter->score[4+questionNum] <<  "," << "NULL" <<  "," << "NULL" << "," << iter->score[4+2*questionNum] << "," << iter->score[4+3*questionNum] << "," << "NULL" << "," << csvHandlerStr(iter->comment) <<std::endl;
    }
    //dronesig
    for (std::vector<SubjectResult>::const_iterator iter = resultdronesig.cbegin(); iter != resultdronesig.cend(); iter++)
    {
        oFile << iter->id + num_sigdrone << "," << iter->age << "," << iter->gender << "," << iter->dronex <<  "," << iter->score[4] <<  "," << "NULL" <<  "," << "NULL" <<  "," << iter->score[4+questionNum] <<  "," << iter->score[4+2*questionNum] << "," << "NULL" << "," <<"NULL" << "," << iter->score[4+3*questionNum] << "," << csvHandlerStr(iter->comment) <<std::endl;
    }
    oFile.close();
    
    
    //打开要输出的文件
    std::ifstream iFile("/Users/qiu/PycharmProjects/drone/scoresheet1.csv");
    std::string   readStr((std::istreambuf_iterator<char>(iFile)),  std::istreambuf_iterator<char>());
    std::cout <<  readStr.c_str()<<std::endl;;
    
    std::ifstream iiFile("/Users/qiu/PycharmProjects/drone/scoresheet2.csv");
    std::string   rreadStr((std::istreambuf_iterator<char>(iiFile)),  std::istreambuf_iterator<char>());
    std::cout <<  rreadStr.c_str()<<std::endl;;
    
    std::ifstream iiiFile("/Users/qiu/PycharmProjects/drone/scoresheet3.csv");
    std::string   rrreadStr((std::istreambuf_iterator<char>(iiiFile)),  std::istreambuf_iterator<char>());
    std::cout <<  rrreadStr.c_str()<<std::endl;;
    
    std::ifstream iiiiFile("/Users/qiu/PycharmProjects/drone/scoresheet4.csv");
    std::string   rrrreadStr((std::istreambuf_iterator<char>(iiiiFile)),  std::istreambuf_iterator<char>());
    std::cout <<  rrrreadStr.c_str()<<std::endl;;
    
    std::ifstream iiiiiFile("/Users/qiu/PycharmProjects/drone/scoresheet5.csv");
    std::string   rrrrreadStr((std::istreambuf_iterator<char>(iiiiiFile)),  std::istreambuf_iterator<char>());
    std::cout <<  rrrrreadStr.c_str()<<std::endl;;
    
    
    
}


void saveSigDroneCSV(SubjectResultVec resultsigdrone)
{
    int questionNum = 5;
    //定义文件输出流
    std::ofstream oFile;
    
    uint num_sigdrone = resultsigdrone.size();
    std::cout << num_sigdrone <<std::endl;
    
    //
    oFile.open("/Users/qiu/PycharmProjects/drone/scoresheetSigDrone.csv", std::ios::out | std::ios::trunc);    // 这样就很容易的输出一个需要的excel 文件
    oFile << "id" << "," << "age" << "," << "gender" << "," << "expertise"  <<  "," << "Seaworld_GSP_q1" <<  "," << "Seaworld_GSP_q2" <<  "," << "Seaworld_GSP_q3" <<  "," << "Seaworld_GSP_q4" <<  "," << "Seaworld_GSP_q5" <<  "," << "University_manu_q1" << "," << "University_manu_q2" << "," << "University_manu_q3" << "," << "University_manu_q4" << "," << "University_manu_q5" <<  "," << "Bay_GSP_q1" << "," << "Bay_GSP_q2" << "," << "Bay_GSP_q3" << "," << "Bay_GSP_q4" << "," << "Bay_GSP_q5" << "," <<"Beach_manu_q1" <<"," <<"Beach_manu_q2" <<"," <<"Beach_manu_q3" <<"," <<"Beach_manu_q4" <<"," <<"Beach_manu_q5" <<  "," << " comment" <<std::endl;
    //sigdrone
    for (std::vector<SubjectResult>::const_iterator iter = resultsigdrone.cbegin(); iter != resultsigdrone.cend(); iter++)
    {
        oFile << iter->id << "," << iter->age << "," << iter->gender << "," << iter->dronex  <<  "," << iter->score[0] <<  "," << iter->score[1] <<  "," << iter->score[2] <<  "," << iter->score[3] <<  "," << iter->score[4] <<  "," << iter->score[5] << "," << iter->score[6] << "," << iter->score[7] << "," << iter->score[8] << "," << iter->score[9] <<  "," << iter->score[10] << "," << iter->score[11] << "," << iter->score[12] << "," << iter->score[13] << "," << iter->score[14] << "," <<iter->score[15] <<"," <<iter->score[16] <<"," <<iter->score[17] <<"," <<iter->score[18] <<"," <<iter->score[19] <<  "," << csvHandlerStr(iter->comment) <<std::endl;
    }
    oFile.close();
    
    
}

void saveDroneSigCSV(SubjectResultVec resultdronesig)
{
    int questionNum = 5;
    //定义文件输出流
    std::ofstream oFile;
    
    uint num_sigdrone = resultdronesig.size();
    std::cout << num_sigdrone <<std::endl;
    
    //
    oFile.open("/Users/qiu/PycharmProjects/drone/scoresheetDroneSig.csv", std::ios::out | std::ios::trunc);    // 这样就很容易的输出一个需要的excel 文件
    oFile << "id" << "," << "age" << "," << "gender" << "," << "expertise"  <<  "," << "Seaworld_manu_q1" <<  "," << "Seaworld_manu_q2" <<  "," << "Seaworld_manu_q3" <<  "," << "Seaworld_manu_q4" <<  "," << "Seaworld_manu_q5" <<  "," << "University_GSP_q1" << "," << "University_GSP_q2" << "," << "University_GSP_q3" << "," << "University_GSP_q4" << "," << "University_GSP_q5" <<  "," << "Bay_manu_q1" << "," << "Bay_manu_q2" << "," << "Bay_manu_q3" << "," << "Bay_manu_q4" << "," << "Bay_manu_q5" << "," <<"Beach_GSP_q1" <<"," <<"Beach_GSP_q2" <<"," <<"Beach_GSP_q3" <<"," <<"Beach_GSP_q4" <<"," <<"Beach_GSP_q5" <<  "," << " comment" <<std::endl;
    //sigdrone
    for (std::vector<SubjectResult>::const_iterator iter = resultdronesig.cbegin(); iter != resultdronesig.cend(); iter++)
    {
        oFile << iter->id << "," << iter->age << "," << iter->gender << "," << iter->dronex  <<  "," << iter->score[0] <<  "," << iter->score[1] <<  "," << iter->score[2] <<  "," << iter->score[3] <<  "," << iter->score[4] <<  "," << iter->score[5] << "," << iter->score[6] << "," << iter->score[7] << "," << iter->score[8] << "," << iter->score[9] <<  "," << iter->score[10] << "," << iter->score[11] << "," << iter->score[12] << "," << iter->score[13] << "," << iter->score[14] << "," <<iter->score[15] <<"," <<iter->score[16] <<"," <<iter->score[17] <<"," <<iter->score[18] <<"," <<iter->score[19] <<  "," << csvHandlerStr(iter->comment) <<std::endl;
    }
    oFile.close();
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    SubjectRecordVec recordsigdrone;
    SubjectResultVec resultsigdrone;
    
    int subjectnum_sigdrone =readRecord("/Users/qiu/PycharmProjects/drone/sigdrone.txt", &recordsigdrone);
    std::cout << "Hello, World!\n We have " << subjectnum_sigdrone << " sample(s) of sigdrone" <<std::endl;
    printRecordVec(recordsigdrone);
    getResult(recordsigdrone, &resultsigdrone );
    
    analyseResultVecSigdrone(resultsigdrone);
    
    //
    SubjectRecordVec recorddronesig;
    SubjectResultVec resultdronesig;
    
    int subjectnum_dronesig =readRecord("/Users/qiu/PycharmProjects/drone/dronesig.txt", &recorddronesig);
    std::cout << "Hello, World!\n We have " << subjectnum_dronesig << " sample(s) of dronesig" <<std::endl;
    printRecordVec(recorddronesig);
    getResult(recorddronesig, &resultdronesig);
    
    analyseResultVecSigdrone(resultdronesig);
    
    saveCSV(resultsigdrone,resultdronesig);
    saveDroneSigCSV(resultdronesig);
    saveSigDroneCSV(resultsigdrone);

    return 0;
}
