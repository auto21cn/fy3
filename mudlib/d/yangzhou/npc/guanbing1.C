// music   yangzhou's ����

inherit NPC;

void create()
{
	set_name("Ѳ�߹ٱ�", ({ "guan bing", "bing", "guanbing" }) );
	set("gender", "����" );
	set("age", 20);
	set("long",
		"Ѳ�ߵĹٱ���\n");
	set("mingwang", 1);
	set("combat_exp", 80000);
        set("str", 30);
        set("cps", 20);
        set("con", 20);
        set("int", 20);
        set_skill("dodge",60);
        set_skill("unarmed",50);
	set_skill("parry",80);
	set_skill("blade",70);
	set("attitude", "peaceful");
	set("chat_msg", ({
		(: random_move :)
	}) );
	setup();
        carry_object("/obj/armor/tiejia")->wear();
        carry_object(__DIR__"obj/gangdao")->wield();
	add_money("silver", 20);
}
int accept_fight(object me)
{
        message_vision("Ѳ�߹ٱ���$N����һ�ɣ��ȵ���߾���󵨣��������£�\n\n", me);
        return 0;
}
/*
int heal_up()
{

        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        object stone;

        this_object()->add("time", 1);
        if( (int)this_object()->query("time") >= 3 ) {
        message("vision",name() + "���˿���ĭ��������´α������������
Ѳ�߹ٱ����˳�ȥ��\n", environment(),this_object() );
        destruct(this_object());

        }
        return;
}

*/

