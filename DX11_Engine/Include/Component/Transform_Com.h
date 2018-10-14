#pragma once
#include "Component_Base.h"
JEONG_BEGIN

//Transform_Com������ World����� ��������Ͽ� S R T���ո� ���ش�!
//SIMD ���п��� Matrix�� ����Ұ��̹Ƿ� 16����Ʈ ����.
class GameObject;
class Component_Base;
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

	Vector3 GetLocalSacle() const { return m_LocalScale; }
	Vector3 GetLocalRotation() const { return m_LocalRotation; }
	Vector3 GetLocalPos() const { return m_LocalPos; }
	Vector3 GetLocalAxis(AXIS eAxis) const { return m_LocalAxis[eAxis]; }
	const Vector3* GetLocalAxis() const { return m_LocalAxis; }
	Matrix GetLocalMatrix()	const { return m_MatLocal; }

	Vector3 GetWorldSacle() const { return m_WorldScale; }
	Vector3 GetWorldRotation() const { return m_WorldRotation; }
	float GetWorldRotationX() const { return m_WorldRotation.x; }
	float GetWorldRotationY() const { return m_WorldRotation.y; }
	float GetWorldRotationZ() const { return m_WorldRotation.z; }
	Vector3 GetWorldPos() const { return m_WorldPos; }
	Vector3 GetWorldAxis(AXIS eAxis) const { return m_WorldAxis[eAxis]; }
	const Vector3* GetWorldAxis() const { return m_WorldAxis; }
	Matrix GetWorldMatrix()	const { return m_MatWorld; }
	float GetAngle(GameObject* Target);
	float GetAngle(Transform_Com* Target);

	//�ȿ����̴� ���ΰ���?
	void SetIsStatic(bool isStatic) { m_isStatic = isStatic; }

	void SetLocalScale(const Vector3& vScale);
	void SetLocalScale(float x, float y, float z);
	void SetLocalRotation(const Vector3& vRot);
	void SetLocalRotation(float x, float y, float z);
	void SetLocalRotX(float x);
	void SetLocalRotY(float y);
	void SetLocalRotZ(float z);
	void SetLocalPos(const Vector3& vPos);
	void SetLocalPos(float x, float y, float z);
	void ComputeLocalAxis();

	void SetWorldScale(const Vector3& vScale);
	void SetWorldScale(float x, float y, float z);
	void SetWorldRotX(float x);
	void SetWorldRotY(float y);
	void SetWorldRotZ(float z);
	void SetWorldPos(const Vector3& vPos);
	void SetWorldPos(float x, float y, float z);
	void ComputeWorldAxis();

	void Move(AXIS eAxis, float Speed);
	void Move(AXIS eAxis, float Speed, float DeltaTime);
	void Move(const Vector3& vDir, float Speed);
	void Move(const Vector3& vDir, float Speed, float DeltaTime);
	void Move(const Vector3& vMove);
	void RotationX(float x);
	void RotationX(float x, float DeltaTime);
	void RotationY(float y);
	void RotationY(float y, float DeltaTime);
	void RotationZ(float z);
	void RotationZ(float z, float DeltaTime);
	void Rotation(const Vector3& vRot, float DeltaTime);
	void Rotation(const Vector3& vRot);

	void LookAt(GameObject* object, AXIS eAxis = AXIS_Z);
	void LookAt(Component_Base* component, AXIS eAxis = AXIS_Z);
	void LookAt(const Vector3& Vec, AXIS eAxis = AXIS_Z);

private:
	//��Ŀ����� ������ü�� ���̱� ������ ������ ���ٶ��� ���ְڴ�.
	bool m_isStatic;	///������ �ִ³��� ������ �ʿ䰡 ����
	bool m_isUpdate;	///�����ϳ� ������Ʈ�ϰڴ�.
	
	//Rocal
	Vector3 m_LocalScale;
	Vector3 m_LocalRotation;
	Vector3 m_LocalPos;
	Vector3 m_LocalAxis[AXIS_MAX];
	
	Matrix m_MatLocalScale;
	Matrix m_MatLocalPos;
	Matrix m_MatLocalRotation;
	Matrix m_MatLocalRotationX;
	Matrix m_MatLocalRotationY;
	Matrix m_MatLocalRotationZ;
	Matrix m_MatLocal;

	//World
	Vector3 m_WorldScale;
	Vector3 m_WorldRotation;
	Vector3 m_WorldPos;
	Vector3 m_WorldAxis[AXIS_MAX];

	Matrix m_MatWorldScale;
	Matrix m_MatWorldPos;
	Matrix m_MatWorldRotation;
	Matrix m_MatWorldRotationX;
	Matrix m_MatWorldRotationY;
	Matrix m_MatWorldRotationZ;
	Matrix m_MatWorld;
	Matrix m_MatParent;

private:
	Transform_Com();
	Transform_Com(const Transform_Com& copyObject);
	~Transform_Com() override;

public:
	friend class GameObject;
};

JEONG_END