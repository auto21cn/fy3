inherit NPC;
inherit F_VENDOR;


void create()
{
       	set_name("���", ({"jin dafu","jin","dafu"}));
       	set("gender", "����");
        set("combat_exp", 10000);
       	set("age", 26);
	set("title", "�鱦���ϰ�");
       	set("per", 14);
       	set("attitude", "friendly");
       	set("shen_type", 1);
	set_skill("dodge", 30);
	set_skill("parry", 30);
       	set_skill("unarmed", 30);
        set("vendor_goods", ([
                "jiezhi": "/d/yangzhou/npc/obj/ring",
                "wanlian": "/d/yangzhou/npc/obj/wrists",
                "xiangquan": "/d/yangzhou/npc/obj/neck",
		"yupei": "/d/yangzhou/npc/obj/pai",
        ]) );

       	setup();
       	carry_object("/d/obj/cloth/choupao")->wear();
       	add_money("silver", 10);
}
void init()
{
	        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {  // 1/3 chance to greet.
                case 0:
                        say(name()+ "Ц�����˵������λ" +
RANK_D->query_respect(ob)
                                + "���������������»��Ȼ��������㲻ʶ���ϡ�\n");
                        break;
        }
}

void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("help!");

        ob=present("guanbing1");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/yangzhou/npc/guanbing1");
                ob->move(environment());
        }
        message_vision("\n��Ȼ������������Ѳ�߹ٱ�����$N��һ������ʲô����ɱ��ı��ô��\n\n",me);        

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
int regenerate()
{
        set("called", 0);
        return 1;
}
