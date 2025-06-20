#pragma once
#include <functional>

class Sheep
{
public:
	Sheep();
	int IncreaseAge();
	void SetGiveBirthCallback(std::function<void(int, int)> callback);
	void CallGiveBirthCB(int id, int numSheepsBorned);
	void SetDeathCallback(std::function<void(int, int)> callback);
	void CallDeathCB(int id, int age);
	void Sheer();
	void ResetSheeredStatus();

	int GetId() const;
	int GetAge() const;
	bool IsSheered() const;
	static int sNextId; //track the next unique id
private:
	std::function<void(int, int)> mGiveBirthCallback;
	std::function<void(int, int)> mDeathCallback;
	bool mIsSheered;
	int mId;
	int mAge;
	int mLastSheeredAge;
};