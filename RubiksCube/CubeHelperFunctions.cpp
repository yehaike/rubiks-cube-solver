#include "pch.h"
#include "CubeHelperFunctions.h"

CubeCommand OppositeCommand(CubeCommand command)
{
	switch(command)
	{
	case CubeCommandLeft:
			return CubeCommandLeftPrime; break;
	case CubeCommandLeftPrime:
			return CubeCommandLeft; break;
	case CubeCommandRight:
			return CubeCommandRightPrime; break;
	case CubeCommandRightPrime:
			return CubeCommandRight; break;
	case CubeCommandTop:
			return CubeCommandTopPrime; break;
	case CubeCommandTopPrime:
			return CubeCommandTop; break;
	case CubeCommandBottom:
			return CubeCommandBottomPrime; break;
	case CubeCommandBottomPrime:
			return CubeCommandBottom; break;
	case CubeCommandFront:
			return CubeCommandFrontPrime; break;
	case CubeCommandFrontPrime:
			return CubeCommandFront; break;
	case CubeCommandBack:
			return CubeCommandBackPrime; break;
	case CubeCommandBackPrime:
			return CubeCommandBack; break;
	}

	assert(false);
	return CubeRotateY;
}

DirectX::XMFLOAT4 ColorToXMFLOAT4(StickerColor c)
{
	switch(c)
	{
	case CUBE_RED:
		return DirectX::XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f);
	case CUBE_WHITE:
		return DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	case CUBE_ORANGE:
		return DirectX::XMFLOAT4(1.0f, 0.45f, 0.0f, 1.0f);
	case CUBE_BLUE:
		return DirectX::XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);
	case CUBE_GREEN:
		return DirectX::XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);
	case CUBE_YELLOW:
		return DirectX::XMFLOAT4(1.0f, 0.8f, 0.0f, 1.0f);
	case CUBE_PINK:
		return DirectX::XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f);
	case CUBE_BLACK:
	default:
		return DirectX::XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f);
	}
}

DirectX::XMFLOAT4X4 XMMATRIXToXMFLOAT4X4(DirectX::XMMATRIX *pInput)
{
	DirectX::XMFLOAT4X4 a;
	DirectX::XMStoreFloat4x4(&a, *pInput);
	return a;
}

DirectX::XMFLOAT3 AddXM3(DirectX::XMFLOAT3 input1, DirectX::XMFLOAT3 input2)
{
	return DirectX::XMFLOAT3(input1.x + input2.x, input1.y + input2.y, input1.z + input2.z);
}

DirectX::XMFLOAT3 MultXM3(DirectX::XMFLOAT3 input1, float input2)
{
	return DirectX::XMFLOAT3(input1.x * input2, input1.y * input2, input1.z * input2);
}

bool IsPrimeCubeCommand(CubeCommand com)
{
	return (com == CubeCommandBackPrime || com == CubeCommandFrontPrime || 
				com == CubeCommandLeftPrime || com == CubeCommandRightPrime ||
				com == CubeCommandTopPrime || com == CubeCommandBottomPrime);
}