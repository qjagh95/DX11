#include "Texture.h"
#include "../PathManager.h"
#include "../Device.h"

JEONG_USING

Texture::Texture()
	:m_ShaderResourceView(NULLPTR)
{
	memset(m_FullPath, 0, sizeof(TCHAR) * MAX_PATH);
}

Texture::~Texture()
{
	SAFE_RELEASE(m_ShaderResourceView);
	Safe_Delete_VecList(m_vecImage);
}

bool Texture::LoadTexture(const string & TextureName, const TCHAR * FileName, const string & PathKey)
{
	const TCHAR* Path = PathManager::Get()->FindPath(PathKey);
	TCHAR FullPath[MAX_PATH] = {};

	if (Path != NULLPTR)
		lstrcpy(FullPath, Path);

	lstrcat(FullPath, FileName);

	return LoadTextureFromFullPath(TextureName, FullPath);
}

bool Texture::LoadTextureFromFullPath(const string & TextureName, const TCHAR * FullPath)
{
	SetTag(TextureName);
	lstrcpy(m_FullPath, FullPath);

	TCHAR Sep[_MAX_EXT] = {};
	char mSep[_MAX_EXT] = {};

#ifdef UNICODE
	//파일의 .확장자를 가져온다. ex(.jpeg, .png, .bmp)
	_wsplitpath_s(FullPath, NULLPTR, 0, NULLPTR, 0, NULLPTR, 0, Sep, _MAX_EXT);
	WideCharToMultiByte(CP_UTF8, 0, Sep, -1, mSep, lstrlen(Sep), 0, 0);
#else
	_splitpath_s(FullPath, NULLPTR, 0, NULLPTR, 0, NULLPTR, 0, mSep, _MAX_EXT);
#endif
	//모든걸 대문자로 바꿔주는 함수.
	_strupr_s(mSep);

	ScratchImage* newImage = new ScratchImage();

	if (strcmp(mSep, ".DDS") == 0)
	{
		if (FAILED(LoadFromDDSFile(FullPath, DDS_FLAGS_NONE, NULLPTR, *newImage)))
			return false;
	}
	if (strcmp(mSep, ".TGA") == 0)
	{
		if (FAILED(LoadFromTGAFile(FullPath, NULLPTR, *newImage)))
			return false;
	}
	else
	{
		if (FAILED(LoadFromWICFile(FullPath, WIC_FLAGS_NONE, NULLPTR, *newImage)))
			return false;
	}

	m_vecImage.push_back(newImage);

	return CreateShaderResource();
}

void Texture::SetShaderResource(int RegisterNumber)
{
	Device::Get()->GetContext()->PSSetShaderResources(RegisterNumber, 1, &m_ShaderResourceView);
}

bool Texture::CreateShaderResource()
{
	if (FAILED(CreateShaderResourceView(Device::Get()->GetDevice(), m_vecImage[0]->GetImages(), m_vecImage[0]->GetImageCount(), m_vecImage[0]->GetMetadata(), &m_ShaderResourceView)))
		return false;

	return true;
}