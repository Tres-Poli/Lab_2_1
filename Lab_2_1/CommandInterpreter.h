#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "ProgramStrategies.h"

class CommandInterpreter
{
private:
    const char* _loadGraph      = "loadgraph";
    const char* _configGraph    = "configgraph";
    const char* _help           = "help";
    const char* _exit           = "exit";
    const char* _generateGraph  = "gengraph";

    ProgramStrategies* _exec = new ProgramStrategies();

    static enum Commands
    {
        LoadGraph,
        GenerateGraph,
        Unrecognized,
        ConfigGraph,
        Help,
        Exit
    };

    int InterpreteCommand(std::string command)
    {
        if (command == _loadGraph)      return LoadGraph;
        if (command == _configGraph)    return ConfigGraph;
        if (command == _help)           return Help;
        if (command == _exit)           return Exit;
        if (command == _generateGraph)  return GenerateGraph;
                                        return Unrecognized;
    }

    // command contains of commandName[0] and arguments [1], [2], [3], ...
    bool DefineStrategy(std::vector<std::string> command)
    {
        int commandNum = InterpreteCommand(command[0]);
        switch (commandNum)
        {
            case LoadGraph:
            {
                if (command[1].empty())
                {
                    std::cout << "File name is not specified. Define it as a first argument of command\n";
                    break;
                }
                _exec->LoadGraphStrategy(command[1]);
                break;
            }
            case ConfigGraph:
            {
                if(command.size() != 3)
                {
                    std::cout << "Arguments are not specified. Define them as a first and second arguments of command\n";
                    break;
                }
                if (command[1].empty() || command[2].empty())
                {
                    std::cout << "Arguments are not specified. Define them as a first and second arguments of command\n";
                    break;
                }
                _exec->ConfigGraphStrategy(std::stoi(command[1]), std::stoi(command[2]));
                break;
            }
            case GenerateGraph:
            {
                _exec->GenerateGraphStrategy();
                break;
            }
            case Help:
            {
                std::cout << "Im nearby, ask me plz ^^\n";
                break;
            }
            case Unrecognized:
            {
                std::cout << "Command unrecognized. Type \"help\" to see all available commands\n";
                break;
            }
            case Exit:
            {
                delete(_exec);
                return true;
            }
        }
        return false;
    }

public:
    void Start()
    {
        while (true)
        {
            std::cout << ">>> ";

            std::vector<std::string> fullCommand;
            std::string currCommand;
            std::getline(std::cin, currCommand);

            std::string commandPart;
            for (int i = 0; i < currCommand.length(); ++i)
            {
                if (currCommand[i] == ' ' && !commandPart.empty())
                {
                    fullCommand.push_back(commandPart);
                    commandPart.clear();
                }
                else
                {
                    commandPart.push_back(currCommand[i]);
                }
            }
            fullCommand.push_back(commandPart);
            if (DefineStrategy(fullCommand)) break;

            fullCommand.clear();
        }
    }
};