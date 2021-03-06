//music yangzhou' 书生
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("都大锦", ({ "du dajin","du"}) );
	set("gender", "男性" );
	set("age", 36);
	set("nickname",YEL"多臂熊"NOR);
	set("combat_exp",1000000);
	set("long",
		"龙门镖局的总镖头，听说是少林寺俗家弟子。\n");
	set("mingwang",1);
	set("attitude", "peaceful");
	set_skill("unarmed",150);
	set_skill("jingang-quan",150);
	set_skill("dodge",150);
	set_skill("shaolin-shenfa",150);
	set_skill("force",150);
	set_skill("hunyuan-yiqi",150);
	set_skill("parry",150);
	set_skill("sword",150);
	set_skill("damo-jian",150);
	map_skill("unarmed","jingang-quan");
	map_skill("dodge","shaolin-shenfa");
	map_skill("parry","jingang-quan");
	map_skill("force","hunyuan-yiqi");
	map_skill("sword","damo-jian");
	set("max_force",1500);
	set("force",1500);
	set("force_factor",100);
	set("max_kee",1200);
	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/std/armor/tongjia")->wear();
	carry_object("/obj/std/armor/tongxue")->wear();
	carry_object("/obj/std/armor/tongkui")->wear();
	carry_object("/obj/std/armor/tongshoutao")->wear();
	carry_object("/obj/weapon/sword")->wield();
}
/*
void init()
{
	::init();
	add_action("do_zhaomu","zhaomu");
}

int do_zhaomu(string arg)
{
	object npc,me=this_player();
	int count=0,number,money,i;
	string biaoshi;
	mapping bs1=([
		"qinglong":"青龙镖师",
		"baihu":"白虎镖师",
		"lvbao":"绿豹镖师",
		"chilang":"赤狼镖师",
		"jinshe":"金蛇镖师",
	]);
	mapping bs2=([
		"qinglong":500000,
		"baihu":400000,
		"lvbao":200000,
		"chilang":100000,
		"jinshe":10000,
	]);
	object *guards;

	if(! arg)	{
		write("先看看牌子上的招慕方法吧。\n");
		return 1;
	}
	if(sscanf(arg,"%s %d",biaoshi,number)!=2)	{
		write("先看看牌子上的招慕方法吧。\n");
		return 1;
	}
	if( !bs1[biaoshi])	{
		write("没有这种镖师！\n");
		return 1;
	}
	if(number<=0)		{
		write("你至少得招一位镖师。\n");
		return 1;
	}
	if(number>4)		{
		write("你最多只能招慕四位镖师。\n");
		return 1;
	}
// add by xxy
if (me->query("age")<16)   {
write("16岁都不到，找什么镖师?\n");
return 1;
}
// check if me can zhaomu this time;
	if( time()-(int)me->query("have_zhaomu")<3600)	{
		write("你刚招慕过镖师，待会再说吧。\n");
		return 1;
	}
	me->set("have_zhaomu",time());
// check if me is guarded by other npc or player;
	guards=me->query_temp("guarded");
	if(sizeof(guards))	{
	for(i=0;i<sizeof(guards);i++)	{
		if(objectp(guards[i]))	{
			write("你正被"+guards[i]->query("name")+"保护着，没法招慕镖师。\n");
			return 1;
		}
	}
	}
	me->delete_temp("guarded");
// check the biaoshi's number,should <40
	count+=sizeof(children("/d/zhongzhou/npc/qinglong"));
	count+=sizeof(children("/d/zhongzhou/npc/bahu"));
	count+=sizeof(children("/d/zhongzhou/npc/lvbao"));
	count+=sizeof(children("/d/zhongzhou/npc/chilang"));
	count+=sizeof(children("/d/zhongzhou/npc/jinshe"));
	if(count>=10)		{
		write("都大锦道：本局镖师都被招慕光了，你下次早点来吧。\n");
		return 1;
	}

// check the money
	money=(int)bs2[biaoshi]*number;
	if( !me->pay_money(money))	{
		write("都大锦道：你身上的现钱不够啊，想让我们喝西北风不成？\n");
		return 1;
	}

// create npc and guard me
	for(i=0;i<number;i++)	{
		npc=new("/d/zhongzhou/npc/"+biaoshi);
		npc->move(environment(me));
		npc->set_leader(me);
		me->add_temp("guarded",({ npc }));
		npc->set_temp("guarding",me);
		call_other(npc,"wait_reset");
	}
	message_vision("$N收下了$n的"+chinese_number(money/10000)+"两黄金道：您请稍候。\n接着一招手，叫出"+chinese_number(number)+"名"+bs1[biaoshi]+"道：好好保护"+me->query("name")+"啊。\n随后冲$n一抱拳道：这位"+RANK_D->query_respect(me)+"如要遣返保镖，请使用unguard指令。\n",this_object(),me);
	return 1;
}
*/
