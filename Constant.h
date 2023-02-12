#pragma once
#include<string>
#include<time.h>

//�D��x
enum class PRIORITY
{
	IMMEDIATELY,	//���}
	HIGHER,			//����
	GENERALLY,		//�ʏ�
	LOWER,			//���
	ERROR
};


//�^�C���f�[�^
typedef struct
{
	unsigned short year;	// �N
	unsigned short month;	// ���i1�`12�j
	unsigned short day;		// ���i1�`31�j

	unsigned short hour;	// ���i0�`23�j
	unsigned short min;		// ���i0�`59�j
	unsigned short sec;		// �b�i0�`59�j
	unsigned short msec;	// �~���b�i0�`999�j

	unsigned short wday;	// �j���i0:���j�`6:�y�j�j
	unsigned short yday;	// �P�N�̂����̓��i0�`365�j

} TIMEDATA;

//�X�e�[�^�X
enum class STATUS
{
	NEW,			//�V�K
	WORKING,		//����
	WAITING,		//������
	COMPLETED,		//����
	DISCONTINUED,	//���~
	PENDING,		//�ۗ�
	ERROR
};

//���[�U�[�f�[�^
struct USERDATA
{
	//ID
	long id;

	//���O
	std::string name;

	//����
	std::string affiliation;

	USERDATA(const std::string& name, const std::string& affiliation);

	USERDATA(long id, const std::string& name, const std::string& affiliation);

	USERDATA() = default;
};

//�G���[�̎��ɕԂ��萔
const USERDATA ERRORDATA = {-1,"ERROR","EXCEPTION"};

long GetRand(long min, long max);

void GetEnter();

struct TaskData
{
	//�^�X�NID
	long id;

	//�S����
	USERDATA pic;

	//�^�C�g��
	std::string title;

	//���e
	std::string content;

	//�D��x
	PRIORITY priority;

	//�X�^�[�g����
	TIMEDATA startTime;

	//�I���\�莞��
	TIMEDATA endTime;

	//�c�莞��
	TIMEDATA remainingTime;

	//�X�e�[�^�X
	STATUS status;
};