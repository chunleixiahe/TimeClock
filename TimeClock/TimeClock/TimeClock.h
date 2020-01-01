#pragma once

typedef void(*CALLBACKFUNC)(void*);

class TimeClock {
public:
	TimeClock();
	~TimeClock();

	bool setTimeWork(std::wstring work_name, int timeInterval, CALLBACKFUNC func, void * args,int counts = 0, bool is_Run = false); //���ö�ʱ����
	bool startWork(std::wstring work_name); //��������
	bool stopWork(std::wstring work_name);
private:
	std::vector<std::wstring> m_vec_workname;              //����������
};