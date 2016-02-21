// cloth.c
//
// This is the basic equip for players just login.
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("�����",({"tuling fu","fu"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","��");
set("value",2000);
	set("long","һ�Ż�������ַ��ŵķ���������fly [����]ʹ������\n"+
"Ŀǰ����ȥ�ĳ����У�\n"+
"zhongzhou��yangzhou��jingcheng��suzhou��hangzhou��quanzhou��\n"+
"kaifeng��chengdu��dali��yanjing��hainan��taiwan��japan��\n"+
"Ŀǰ����ȥ�������У�\n"+
"mingjiao��taishan��hengshan��songshan��huashan��yandang��riyue��\n"+
"quanzhen��wudang��emei��baituo��lingjiu��meizhuang��\n");
		set("material","paper");
	}
	setup();
}
void init()
{
	add_action("do_fly","fly");
}
int do_fly(string str)
{
	object me;
	string dest;
	me=this_player();
	if(living(me)==0)	return 0;
	if(environment(this_object())!=me)	return 0;
            if( me->is_fighting() )
                    return notify_fail("ս���в��ܷɡ�\n");
	if(!str)   {
		tell_object(me,"��Ҫ��������ɵ��Ķ���\n");
		return 1;
	}
	        if(environment(me)->query("no_fight"))  {
			tell_object(me,"�������ʹ���������\n");
                return 1;
        }

	if(str=="yangzhou")	dest="/d/yangzhou/shizhongxin";
	else if(str=="suzhou")   dest="/d/suzhou/chengzhong";
	else if(str=="hangzhou")	dest="/d/hangzhou/ximen";
	else if(str=="zhongzhou")	dest="/d/zhongzhou/shizhongxin";
	else if(str=="jingcheng")	dest="/d/huanggon/yongdingmen";
	else if(str=="quanzhou")	dest="/d/quanzhou/nstreet3";
	else if(str=="dali")	dest="/d/dali/dalinorth";
	else if(str=="kaifeng")	dest="/d/kaifeng/zhuque";
	else if(str=="chengdu")	dest="/d/chengdu/eastchengmen";
	else if(str=="yanjing")	dest="/d/yanjing/gate";
	else if(str=="hainan")	dest="/d/hainan/haibian";
	else if(str=="taiwan")	dest="/d/taiwan/matou";
	else if(str=="japan")	dest="/d/japan/zhongxin";
	else if(str=="mingjiao")	dest="/d/mingjiao/shanmen";
	else if(str=="taishan")	dest="/d/taishan/taishanjiao";
	else if(str=="hengshan")	dest="/d/hengshan/jinlongxia";
	else if(str=="songshan")	dest="/d/songshan/taishique";
	else if(str=="huashan")	dest="/d/huashan/path1";
	else if(str=="yandang")	dest="/d/yandang/jiedao";
	else if(str=="riyue")	dest="/d/heimuya/road1";
	else if(str=="quanzhen")	dest="/d/quanzhen/damen";
	else if(str=="wudang")	dest="/d/wudang/guangchang";
	else if(str=="emei")	dest="/d/emei/road";
	else if(str=="baituo")	dest="/d/baituo/damen";
	else if(str=="lingjiu")	dest="/d/lingjiu/shanjiao";
	else if(str=="meizhuang")	dest="/d/meizhuang/meizhuang";
	else 	{
		return notify_fail("������޷���������Ƕ���\n");
	}
	message_vision(YEL"$N���е����������������â����$N������������������\n\n$N����Ӱ��ʧ�ڹ�â�С�����\n\n��â����$N�ټ�������\n"NOR,me);
	me->move(dest);
	message_vision(YEL"��Զ����һ�������֣�$N����Ӱ�����ڽ��֮�У�\n"NOR,me);
	destruct(this_object());
	return 1;
}