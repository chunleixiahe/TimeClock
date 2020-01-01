// TimeClock.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "TimeClock.h"
#include <iostream>

using namespace std;

TimeClock::TimeClock()
{

}

TimeClock::~TimeClock()
{

}

//设置计时任务
//@params:work_name: 任务名
//@params:timeInterval:设置时间间隔 即何时开始执行该任务 ：默认情况下 是大于10;
//@params:func:回调函数
//@params:args:回调函数的参数
//@param: counts:执行次数:默认为0，即不设置次数
//@param: is_Run: true:立即执行，false:手动运行，默认手动
//@return: true:设置成功，false：设置失败
bool TimeClock::setTimeWork(std::wstring work_name, int timeInterval,CALLBACKFUNC func,void * args, int counts,bool is_Run)
{
	//先判断大小
	if (work_name.size()>0)
	{
		m_vec_workname.push_back(work_name); //添加该工作文件名
	}
	else
	{
		cout << "任务名有错" << endl;
		return false;
	}
	if (timeInterval < 10)
	{
		cout << "timeInterval间隔需要大于10" << endl;
		return false;
	}
	if (counts <0)
	{
		cout << "循环次数不能小于0" << endl;
		return false;
	}
	if (is_Run == true)
	{
		//提前执行：执行次数为counts次
		if (counts > 0)
		{
			//根据counts 设置执行次数
			clock_t start, finish;
			start = clock();
			cout << "Start Time:";
			cout << start << endl;
			int count_times = 0;
			while (1)
			{
				finish = clock();
				if ((finish - start) == timeInterval)
				{
					count_times++;
					cout << "执行次数"<< count_times << endl;
					func(args);
					start = clock();
					if (count_times == counts)
					{
						//结束这样
						break;
					}
				}
			}
			cout << "执行结束" << endl;
		}
		else
		{

		}
	}
	return true;
}

bool TimeClock::startWork(std::wstring work_name)
{
	return false;
}

bool TimeClock::stopWork(std::wstring work_name)
{
	return false;
}

void backcallfunc(void *arg)
{
	cout << "go to timer1:" << *(double *)arg << endl;
}

int main()
{
	double mm = 123.33;
	backcallfunc(&mm);
	TimeClock * tc = new TimeClock();
	tc->setTimeWork(L"ddd", 111, backcallfunc,&mm,10,true);
	delete tc;
    std::cout << "Hello World!\n"; 
}
