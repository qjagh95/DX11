//쉐이더파일을 중간에 변경이 가능하다.

//예를들어 배경이미지를 그냥 출력하다가 갑자기 피격시 빨간 배경으로 바껴야한다면 빨강쉐이더로 순간적으로 체인지 후 
//다시 기본쉐이더로 돌아오기가 가능함 (9에서도 가능)

struct VS_INPUT_COLOR
{
    //시맨틱은 이름 뒤에 숫자를 붙여준다. 안붙일경우 기본으로 0
    float3 vPos : POSITION;
    float4 vColor : COLOR;
};

struct VS_OUTPUT_COLOR
{
    //SV = SystemValue -> 바꿀 수 없다.
    float4 vPos : SV_POSITION;
    float4 vColor : COLOR;
};

struct PS_OUTPUT_SINGLE
{
    float4 vTarget0 : SV_Target;
};