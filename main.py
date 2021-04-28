from random import randint

import serial
import time

leftHand = serial.Serial('com6', 9600)
time.sleep(1)
print(leftHand.readline())
rightHand = serial.Serial('com6', 9600)
time.sleep(1)
print(rightHand.readline())


def Action(impAction: str):
    """Передается действие в виде строки
    При передаче действия Привет рандомно определяется вид приветствия - рукопожатие или брофист
    При передаче неизвестного действия выполняется Неизвестное действие"""

    if impAction == 'Привет':

        helloType = str(randint(0, 1))

        if helloType == '0':
            print('Ответ Python: Рукопожатие')
        else:
            print('Ответ Python: Брофист')

        rightHand.write(helloType.encode())
        print(rightHand.readline())

    elif impAction == 'Патфайндер':

        print('Ответ Python: Патфайндер')

        rightHand.write('2'.encode())
        print(rightHand.readline())

        leftHand.write('2'.encode())
        print(leftHand.readline())

    elif impAction == 'Пока':

        print('Ответ Python: Прощание')

        rightHand.write('3'.encode())
        print(rightHand.readline())

    else:

        print('Ответ Python: Неизвестное действие')

        rightHand.write('4'.encode())
        print(rightHand.readline())

        leftHand.write('4'.encode())
        print(leftHand.readline())
