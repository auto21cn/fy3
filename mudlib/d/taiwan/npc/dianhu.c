inherit NPC;
void create()
{
      set_name("�軧",({"dianhu","man","qiongren"}));
      if (random(2)==1) 
      set("gender","����");
      else set("gender","Ů��");
      set("age",15+random(50));
      set("str",10+random(20));
      set("combat_exp",1000+random(1000));
      set("chat_chance",3);
      set("chat_msg",({
            "�Ų�������ô��ծ,�ɽ�������ô�?\n",
            "�ҿ��治��,��ôȥ���һ����,���˽���ͳ���һ����?\n",
            "��ʦү˵ȥ���һ�������µ�,���˽��궼��ֹһ����!\n",
         }));
     set_skill("dodge",20);
     set_skill("parry",20);
     set_skill("unarmed",20);
     setup();
     carry_object("/obj/cloth")->wear();
     add_money("coin",10+random(20));
}