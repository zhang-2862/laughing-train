#include "inc/workerManager.h"
#include "inc/worker.h"


int main() {

//    //���Դ���
//    Worker *worker = NULL;
//    worker = new Employee(1, "����", 1);
//    worker->showInfo();
//    delete worker;
//
//    worker = new Manager(2, "����", 2);
//    worker->showInfo();
//    delete worker;
//
//    worker = new Boss(3, "����", 3);
//    worker->showInfo();
//    delete worker;


    WorkerManager wm;
    int choice = 0;
    while (true) {
        //չʾ�˵�
        wm.Show_Menu();
        cout << "����������ѡ�� " << endl;
        cin >> choice;//�����û���ѡ��

        switch (choice) {
            case 0://�˳�ϵͳ
                wm.ExitSystem();
                break;
            case 1://���ְ��
                wm.Add_Emp();
                break;
            case 2://��ʾְ��
                wm.Show_Emp();
                break;
            case 3://ɾ��ְ��
                break;
            case 4://�޸�ְ��
                break;
            case 5://����ְ��
                break;
            case 6://����ְ��
                break;
            case 7://����ļ�
                break;
            default:
                break;
        }
    }
    return 0;
}
