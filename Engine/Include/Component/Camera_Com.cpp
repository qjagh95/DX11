#include "Camera_Com.h"
#include "../GameObject.h"
#include "Transform_Com.h"
JEONG_USING

Camera_Com::Camera_Com()
{
	m_ComType = CT_CAMERA;
	m_CameraType = CT_PERSPECTIVE;
}

Camera_Com::~Camera_Com()
{
}

Camera_Com::Camera_Com(const Camera_Com & camera)
	:Component_Base(camera)
{
	m_CameraType = camera.m_CameraType;
	m_View = camera.m_View;
	m_Projection = camera.m_Projection;
}

bool Camera_Com::Init()
{
	return true;
}

int Camera_Com::Input(float DeltaTime)
{
	return 0;
}

int Camera_Com::Update(float DeltaTime)
{
	m_View.Identity();

	//memcpy 41 ~ 43위치 == Pos위치임.
	memcpy(&m_View[3][0], &m_Transform->GetWorldPos(), sizeof(Vector3));

	return 0;
}

int Camera_Com::LateUpdate(float DeltaTime)
{
	return 0;
}

void Camera_Com::Collision(float DeltaTime)
{
}

void Camera_Com::CollisionLateUpdate(float DeltaTime)
{
}

void Camera_Com::Render(float DeltaTime)
{
}

Camera_Com * Camera_Com::Clone()
{
	return new Camera_Com(*this);
}

void Camera_Com::SetCameraType(CAMERA_TYPE eType)
{
	switch (eType)
	{
		case CT_PERSPECTIVE:
			//투영행렬을 만든다(PERSPECTIVE)
			m_Projection = XMMatrixPerspectiveFovLH(DegreeToRadian(m_ViewAngle), m_Width / m_Height, m_Near, m_Far);
			break;
		case CT_ORTHO:
			//ORTHO
			m_Projection = XMMatrixOrthographicOffCenterLH(0, m_Width, m_Height, 0, m_Near, m_Far);
			break;
	}
}

void Camera_Com::SetCameraInfo(CAMERA_TYPE eType, float Width, float Height, float ViewAngle, float Near, float Far)
{
	m_Width = Width;
	m_Height= Height;
	m_Near = Near;
	m_Far = Far;
	m_ViewAngle = ViewAngle;
	
	SetCameraType(eType);
}