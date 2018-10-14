#include "Share.fx"

//fx파일은 버텍스와 픽셀쉐이더 두개 동시에 처리가 가능하다.

VS_OUTPUT_COLOR Standard_Color_VS(VS_INPUT_COLOR input)
{
    //0으로 초기화
    VS_OUTPUT_COLOR output = (VS_OUTPUT_COLOR)0;
    //mul = 곱하기 (벡터행렬곱)
    output.vPos = mul(float4(input.vPos, 1.0f), g_WVP);
    output.vColor = input.vColor;

    return output;
}

//버텍스 쉐이더에서 뱉은 OutPut데이터가 픽셀쉐이더 Input으로 들어온다. (매쉬클래스 랜더에서 이미 다 지정을 해놨다(IA~) )
PS_OUTPUT_SINGLE Standard_Color_PS(VS_OUTPUT_COLOR input)
{
    PS_OUTPUT_SINGLE output = (PS_OUTPUT_SINGLE)0;

    output.vTarget0 = input.vColor;

    return output;
}

///////////////////////////////////////////////////////////////////////////////////////

VS_OUTPUT_UV Standard_UV_VS(VS_INPUT_UV input)
{
    VS_OUTPUT_UV output = (VS_OUTPUT_UV)0;

    output.vPos = mul(float4(input.vPos, 1.0f), g_WVP);
    output.vUV = input.vUV;

    return output;
}

PS_OUTPUT_SINGLE Standard_UV_PS(VS_OUTPUT_UV input)
{
    PS_OUTPUT_SINGLE output = (PS_OUTPUT_SINGLE)0;

    output.vTarget0 = Diffuse.Sample(DiffuseSampler, input.vUV) * g_MaterialDiffuse;

    return output;
}
