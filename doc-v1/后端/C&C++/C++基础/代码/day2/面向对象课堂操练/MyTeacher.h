#pragma once //只包含一次

/*
#ifndef __MYTEACHER_H
#define __MYTEACHER_H
#endif;
*/

class MyTeacher
{
public:
          void setAge(int age);
          int getAge();

private:
          char name[32];
          int m_age;
};
