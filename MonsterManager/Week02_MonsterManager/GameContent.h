#pragma once
class GameContent
{
private:
	static GameContent* mInstance;
	GameContent();

public:
	void GiveStartContent() const;
	void GiveStartContent2() const;
	void GiveMemoryContent1() const;
	void GiveMemoryContent2() const;
	void GiveMemoryContent3() const;
	void GiveMemoryContent4() const;
	void GiveMemoryContent5() const;
	void GiveMemoryContent6() const;
	void GiveMemoryContent7() const;
	void GiveMemoryContentAll() const;

public:
	static GameContent* GetInstance();
	~GameContent();
};

