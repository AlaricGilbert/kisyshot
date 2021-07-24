#include<compiler/codegen.h>
#include<iostream>

using namespace kisyshot::ast;
using namespace kisyshot::compiler;


namespace kisyshot::compiler {

    CodeGenerator::CodeGenerator(){}

    //返回一个不重复的标号
    std::string CodeGenerator::newLabel() {
        static int labelId = 0;
        labelId++;
        return "_label_" + std::to_string(labelId);
    }


    //返回一个不重复的临时变量
    Var *CodeGenerator::newTempVar() {
        static int TempID = 0;
        TempID++;
        std::string name = "_temp_" + std::to_string(TempID);
        Var *t = new Var(name);
        name2VarMap[name] = t; //把声明的临时变量加入map中
        return t;
    }

    void CodeGenerator::genLabel(std::string &label) {
        Label *p = new Label(label);
        code.push_back((Instruction *)p);
        if (printOrNot) {
            std::cout <<  p->toString()  << std::endl;
        }
    }


    //Load指令
     void CodeGenerator::genLoad(Var *src,Var *dst) {
        Load *p = new Load(src, dst);
        code.push_back((Instruction *)p);
        if (printOrNot) {
            std::cout <<  p->toString() << std::endl;
        }
    }

    void CodeGenerator::genAssign(Var *src, Var *dst) {
        auto p = new Assign(src, dst);
        code.push_back((Instruction *)p);
        if (printOrNot) {
            std::cout <<  p->toString() << std::endl;
        }
    }

    void CodeGenerator::genStore(Var *src, Var *dst) {
        auto p = new Store(src, dst);
        code.push_back((Instruction *)p);
        if (printOrNot) {
            std::cout <<  p->toString() << std::endl;
        }
    }

    void CodeGenerator::genBinaryOp(std::string &opName, Var *op1, Var *op2,Var* dst) {
        auto p = new Binary_op(Binary_op::opCodeForName(opName), op1, op2, dst);
        code.push_back((Instruction *)p);
        if (printOrNot) {
            std::cout <<  p->toString() << std::endl;
        }
    }

    void CodeGenerator::genParam(Var *pa) {
        auto p = new Param(pa);
        code.push_back((Instruction *)p);
        if (printOrNot) {
            std::cout <<  p->toString() << std::endl;
        }
    }

    void CodeGenerator::genCall(std::string &funLabel,int n,Var* dst) {
        auto p = new Call(funLabel, n,dst);
        code.push_back((Instruction *)p);
        if(printOrNot) {
            std::cout <<  p->toString() << std::endl;
        }
    }

    void CodeGenerator::genCallNoReturn(std::string &funLabelId, int n) {
        auto p = new Call(funLabelId,n);
        code.push_back((Instruction *)p);
        if(printOrNot) {
            std::cout <<  p->toString() << std::endl;
        }

    }

    void CodeGenerator::genIFZ(Var *condition, std::string &label) {
        auto p = new IfZ(condition, label);
        code.push_back((Instruction *)p);
        if(printOrNot) {
            std::cout <<  p->toString() << std::endl;
        }
    }

    void CodeGenerator::genGOTO(std::string &label) {
        auto p = new GOTO(label);
        code.push_back((Instruction *)p);
        if(printOrNot) {
            std::cout <<  p->toString() << std::endl;
        }
    }

    void CodeGenerator::genReturn(Var *v) {
        auto p = new Return(v);
        code.push_back((Instruction *)p);
        if(printOrNot) {
            std::cout <<  p->toString() << std::endl;
        }
    }

    void CodeGenerator::genBeginFunc() {
        auto p = new BeginFunc();
        code.push_back((Instruction *)p);
        if(printOrNot) {
            std::cout <<  p->toString() << std::endl;
        }
    }

    void CodeGenerator::genEndFunc() {
        auto p = new EndFunc();
        code.push_back((Instruction *)p);
        if(printOrNot) {
            std::cout <<  p->toString() << std::endl;
        }
    }

}