#include "Transform_Com.h"

JEONG_USING

Transform_Com::Transform_Com()
{
	m_ComType = CT_TRANSFORM;
	m_isUpdate = true;
	m_isStatic = false;
}

Transform_Com::Transform_Com(const Transform_Com& copyObject)
	:Component_Base(copyObject)
{
	
}

Transform_Com::~Transform_Com()
{
}

bool Transform_Com::Init()
{
	for (int i = 0; i < 3; i++)
	{
		m_LocalAxis[i] = Vector3::Axis[i];
	}

	return true;
}

int Transform_Com::Input(float DeltaTime)
{
	return 0;
}

int Transform_Com::Update(float DeltaTime)
{
	if (m_isStatic == true)
		return 0;
	else if (m_isUpdate == false)
		return 0;

	//World = S R T결합.
	m_MatWorld = m_MatWorldScale * m_MatWorldRotation * m_MatWorldPos * m_MatParent;

	m_isUpdate = false;

	return 0;
}

int Transform_Com::LateUpdate(float DeltaTime)
{
	if (m_isStatic == true)
		return 0;
	else if (m_isUpdate == false)
		return 0;

	//World = S R T결합.
	m_MatWorld = m_MatWorldScale * m_MatWorldRotation * m_MatWorldPos * m_MatParent;

	m_isUpdate = false;

	return 0;
}

void Transform_Com::Collision(float DeltaTime)
{
}

void Transform_Com::CollisionLateUpdate(float DeltaTime)
{
}

void Transform_Com::Render(float DeltaTime)
{
}

Transform_Com * Transform_Com::Clone()
{
	return new Transform_Com(*this);
}

void Transform_Com::SetLocalScale(const Vector3 & vScale)
{
	//크기값을 받는다
	m_LocalScale = vScale;
	//행렬에 크기값을 곱한다
	m_MatLocalScale.Scaling(m_LocalScale);

	m_isUpdate = true;
}

void Transform_Com::SetLocalScale(float x, float y, float z)
{
	//크기값을 받는다
	m_LocalScale = Vector3(x, y, z);
	//행렬에 크기값을 곱한다
	m_MatLocalScale.Scaling(m_LocalScale);

	m_isUpdate = true;
}

void Transform_Com::SetLocalRotation(const Vector3 & vRot)
{
	//회전값을 받는다
	m_LocalRotation = vRot;
	//회전행렬에 곱해준다
	m_MatLocalRotation.Rotation(m_LocalRotation);

	m_isUpdate = true;
}

void Transform_Com::SetLocalRotation(float x, float y, float z)
{
	//회전값을 받는다
	m_LocalRotation = Vector3(x, y, z);
	//회전행렬에 곱해준다
	m_MatLocalRotation.Rotation(m_LocalRotation);

	m_isUpdate = true;
}

void Transform_Com::SetLocalRotX(float x)
{
	//회전값을 받는다
	m_LocalRotation.x = x;
	//회전행렬에 곱해준다
	m_MatLocalRotation.Rotation(m_LocalRotation);

	m_isUpdate = true;
}

void Transform_Com::SetLocalRotY(float y)
{
	//회전값을 받는다
	m_LocalRotation.y = y;
	//회전행렬에 곱해준다
	m_MatLocalRotation.Rotation(m_LocalRotation);

	m_isUpdate = true;
}

void Transform_Com::SetLocalRotZ(float z)
{
	//회전값을 받는다
	m_LocalRotation.z = z;
	//회전행렬에 곱해준다
	m_MatLocalRotation.Rotation(m_LocalRotation);

	m_isUpdate = true;
}

void Transform_Com::SetLocalPos(const Vector3 & vPos)
{
	m_LocalPos = vPos;

	m_MatLocalPos.Translation(m_LocalPos);

	m_isUpdate = true;
}

void Transform_Com::SetLocalPos(float x, float y, float z)
{
	m_LocalPos = Vector3(x, y, z);

	m_MatLocalPos.Translation(m_LocalPos);

	m_isUpdate = true;
}

//각 축의 방향을 알아온다.
void Transform_Com::ComputeLocalAxis()
{
	for (int i = 0; i < 3; ++i)
	{
		//행렬 곱함수.
		m_LocalAxis[i] = Vector3::Axis[i].TransformNormal(m_MatLocalRotation);
		//크기1벡터로 만들어서 방향값을 얻어오기 위함.
		m_LocalAxis[i].Nomallize();
	}
}

/////////
void Transform_Com::SetWorldScale(const Vector3 & vScale)
{
	//크기값을 받는다
	m_WorldScale = vScale;
	//행렬에 크기값을 곱한다
	m_MatWorldScale.Scaling(m_WorldScale);

	m_isUpdate = true;
}

void Transform_Com::SetWorldScale(float x, float y, float z)
{
	//크기값을 받는다
	m_WorldScale = Vector3(x, y, z);
	//행렬에 크기값을 곱한다
	m_MatWorldScale.Scaling(m_WorldScale);

	m_isUpdate = true;
}

void Transform_Com::SetWorldRotation(const Vector3 & vRot)
{
	//회전값을 받는다
	m_WorldRotation = vRot;
	//회전행렬에 곱해준다
	m_MatWorldRotation.Rotation(m_WorldRotation);

	m_isUpdate = true;
}

void Transform_Com::SetWorldRotation(float x, float y, float z)
{
	//회전값을 받는다
	m_WorldRotation = Vector3(x, y, z);
	//회전행렬에 곱해준다
	m_MatWorldRotation.Rotation(m_WorldRotation);

	m_isUpdate = true;
}

void Transform_Com::SetWorldRotX(float x)
{
	//회전값을 받는다
	m_WorldRotation.x = x;
	//회전행렬에 곱해준다
	m_MatWorldRotation.Rotation(m_WorldRotation);

	m_isUpdate = true;
}

void Transform_Com::SetWorldRotY(float y)
{
	//회전값을 받는다
	m_WorldRotation.y = y;
	//회전행렬에 곱해준다
	m_MatWorldRotation.Rotation(m_WorldRotation);

	m_isUpdate = true;
}

void Transform_Com::SetWorldRotZ(float z)
{
	//회전값을 받는다
	m_WorldRotation.z = z;
	//회전행렬에 곱해준다
	m_MatWorldRotation.Rotation(m_WorldRotation);

	m_isUpdate = true;
}

void Transform_Com::SetWorldPos(const Vector3 & vPos)
{
	m_WorldPos = vPos;

	m_MatWorldPos.Translation(m_WorldPos);

	m_isUpdate = true;
}

void Transform_Com::SetWorldPos(float x, float y, float z)
{
	m_WorldPos = Vector3(x, y, z);

	m_MatWorldPos.Translation(m_WorldPos);

	m_isUpdate = true;
}

//각 축의 방향을 알아온다.
void Transform_Com::ComputeWorldAxis()
{
	for (int i = 0; i < 3; ++i)
	{
		//행렬 곱함수.
		m_WorldAxis[i] = Vector3::Axis[i].TransformNormal(m_MatWorldRotation);
		//크기1벡터로 만들어서 방향값을 얻어오기 위함.
		m_WorldAxis[i].Nomallize();
	}
}
