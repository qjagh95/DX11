#pragma once
#include "Component_Base.h"
JEONG_BEGIN

//SIMD ���п��� Matrix�� ����Ұ��̹Ƿ� 16����Ʈ ����.
class JEONG_DLL __declspec(align(16)) Transform_Com : public Component_Base
{
public:
	bool Init() override;
	int Input(float DeltaTime) override;
	int Update(float DeltaTime) override;
	int LateUpdate(float DeltaTime) override;
	void Collision(float DeltaTime) override;
	void CollisionLateUpdate(float DeltaTime) override;
	void Render(float DeltaTime) override;
	Transform_Com* Clone() override;

private:
	Transform_Com();
	Transform_Com(const Transform_Com& copyObject);
	~Transform_Com() override;

public:
	friend class GameObject;
};

JEONG_END
