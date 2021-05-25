import tkinter as tk
from tkinter import messagebox

SEPARATOR = '-'
NO_TRANSITION = '/'
LEFT = 'l'
RIGHT = 'r'

START_MTD_CODE = '|'
SEPARATOR_MTD_CODE_PART_OF_TRANSITION = '>'
SEPARATOR_MTD_CODE_ELEMENT_OF_TRANSITION = ','
SEPARATOR_MTD_CODE_TRANSITION = ';'
MTD_CODE_FINAL_STATE = '$'
MTD_CODE_CHARACTER = '1'
MTD_CODE_CHARACTER_SEPARATOR = '0'


def copy_into_clipboard(text):
    clipboard = tk.Tk()
    clipboard.withdraw()
    clipboard.clipboard_clear()
    clipboard.clipboard_append(text)
    clipboard.destroy()


def char_range(c1, c2):
    # Generates the characters from `c1` to `c2`, inclusive
    for c in range(ord(c1), ord(c2) + 1):
        yield chr(c)


def get_mtd_code(input_dictionary):
    height, width = max(list(input_dictionary.keys()))
    height += 1
    width += 1

    if is_input_ok(input_dictionary):
        character_dictionary = dict(zip(char_range('a', 'z'), (i for i in range(1, 28))))

        mtd_code = START_MTD_CODE

        for i in range(1, height):
            for j in range(2, width):
                string = input_dictionary[i, j].get()

                if string != NO_TRANSITION:
                    mtd_code += ((i * MTD_CODE_CHARACTER) + SEPARATOR_MTD_CODE_ELEMENT_OF_TRANSITION)
                    mtd_code += ((character_dictionary[input_dictionary[0, j].get()] * MTD_CODE_CHARACTER) +
                                 SEPARATOR_MTD_CODE_PART_OF_TRANSITION)

                    transition = list(string.split(SEPARATOR))
                    state = int((transition[0])[1:])
                    character = transition[1].lower()
                    operation = transition[2].lower()

                    mtd_code += ((state + 1) * MTD_CODE_CHARACTER)

                    # Check if the state is final
                    if input_dictionary[state + 1, 0].get() == '1':
                        mtd_code += MTD_CODE_FINAL_STATE

                    mtd_code += (SEPARATOR_MTD_CODE_ELEMENT_OF_TRANSITION +
                                 (character_dictionary[character] * MTD_CODE_CHARACTER) +
                                 SEPARATOR_MTD_CODE_ELEMENT_OF_TRANSITION)

                    if operation == LEFT:
                        mtd_code += MTD_CODE_CHARACTER
                    else:
                        mtd_code += (MTD_CODE_CHARACTER * 2)

                    mtd_code += SEPARATOR_MTD_CODE_TRANSITION

        window = tk.Tk()
        window.title('Codificatore MdT')
        window.iconbitmap('Resources/icon.ico')
        window.resizable(width=False, height=False)
        window.configure(bg='#A3A3F7')

        label = tk.Label(window, text='Il codice che identifica la MdT specificata prima è il seguente:',
                         font=('', '8', 'bold'))
        label.configure(bg='#A3A3F7')
        label.pack(pady=(20, 5))

        text = tk.Entry(window, text="Codice MdT", font=('', '8', ''), width='36')
        text.insert(0, mtd_code)
        text.configure(state=tk.DISABLED)
        text.pack()

        button = tk.Button(window, text='Copia negli appunti', command=lambda: copy_into_clipboard(mtd_code))
        button.pack(pady=(40, 20))

    else:
        messagebox.showerror('Errore', 'È necessario indicare se l\'i-esimo stato è di accettazione attraverso uno 0 o '
                                       'un 1.\nPer indicare la singola transizione è necessario inserire una tripla '
                                       'del tipo "stato-carattere-operazione".\nLo stato indicato deve essere valido.'
                                       '\nIl carattere indicato deve essere stato indicato in precedenza.'
                                       '\nL\'operazione deve essere indicata dal carattere "l" per indicare il '
                                       'movimento a sinistra o "r" per il movimento a destra.'
                                       '\nPer indicare l\'assenza di una transizione inserire '
                                       'il carattere "' + NO_TRANSITION + '".')


def is_input_ok(input_dictionary):
    input_ok = True

    height, width = max(list(input_dictionary.keys()))
    height += 1
    width += 1

    states = set()
    for i in range(1, height):
        states.add(input_dictionary[(i, 1)].get())

    characters = set()
    for i in range(2, width):
        characters.add(input_dictionary[(0, i)].get())

    # Check if the first column has 0 or 1
    for i in range(1, height):
        if not (input_dictionary[i, 0].get() == '0' or input_dictionary[i, 0].get() == '1'):
            input_ok = False
            break

    for i in range(1, height):
        for j in range(2, width):
            string = input_dictionary[i, j].get()
            transition = list(string.split(SEPARATOR))

            if len(string) == 1 and string == NO_TRANSITION:
                break

            elif len(transition) == 3:
                state = transition[0].lower()
                character = transition[1].lower()
                operation = transition[2].lower()

                # Check state
                if state not in states:
                    input_ok = False
                    break

                # Check character
                if character not in characters:
                    input_ok = False
                    break

                # Check operation
                if not (operation == LEFT or operation == RIGHT):
                    input_ok = False
                    break

            else:
                input_ok = False
                break

    return input_ok


def enter_pressed():
    n_states = str(state_text.get())
    characters = str(character_text.get())

    if n_states.isdigit() and int(n_states) > 0:
        n_states = int(n_states)

        characters = characters.lower()
        characters = characters.replace(" ", "")
        characters = list(set(characters.split(SEPARATOR)))  # Removing duplicates and splitting characters

        show_second_window = True
        for element in characters:
            if len(element) != 1 or element < 'a' or element > 'z':
                messagebox.showerror('Errore', 'I caratteri accettati devono appartenere all\'alfabeto internazionale, '
                                               'devono essere minuscoli, non devono contenere doppioni e devono essere '
                                               'separati dal carattere "' + SEPARATOR + '".')
                show_second_window = False
                break

        if show_second_window:
            first_window.destroy()

            second_window = tk.Tk()
            second_window.title('Codificatore MdT')
            second_window.iconbitmap('Resources/icon.ico')
            second_window.resizable(width=False, height=False)
            second_window.configure(bg='#A3A3F7')

            root_frame = tk.Frame(second_window)
            root_frame.grid()

            title_table = tk.Entry(root_frame, text="Stato Finale")
            title_table.insert(0, "Stato Finale")
            title_table.configure(state=tk.DISABLED)
            title_table.grid(row=0, column=0)

            input_dictionary = {(0, 0): title_table}

            title_table = tk.Entry(root_frame, text="Stati")
            title_table.insert(0, "Stati")
            title_table.configure(state=tk.DISABLED)
            title_table.grid(row=0, column=1)

            input_dictionary[(0, 1)] = title_table

            for j in range(len(characters)):
                title_table = tk.Entry(root_frame, text=characters[j])
                title_table.insert(0, characters[j])
                title_table.configure(state=tk.DISABLED)
                title_table.grid(row=0, column=j + 2)
                input_dictionary[(0, j + 2)] = title_table

            for i in range(n_states):
                for j in range(len(characters) + 2):
                    if j == 1:
                        input_text = tk.Entry(root_frame, text="q" + str(i))
                        input_text.insert(0, "q" + str(i))
                        input_text.configure(state=tk.DISABLED)
                        input_text.grid(row=i + 1, column=j)
                    else:
                        input_text = tk.Entry(root_frame, text="")
                        input_text.grid(row=i + 1, column=j)

                    input_dictionary[(i + 1, j)] = input_text

            button = tk.Button(second_window, text='Invio', command=lambda: get_mtd_code(input_dictionary))
            button.grid(pady=(40, 20))
    else:
        messagebox.showerror('Errore', 'Il numero degli stati deve essere un intero positivo maggiore di 0.'
                                       '\nI caratteri accettati devono appartenere all\'alfabeto internazionale, devono'
                                       ' essere minuscoli, non devono contenere doppioni e devono essere separati dal '
                                       'carattere "' + SEPARATOR + '".')


def reset_pressed():
    state_text.delete(0, tk.END)
    character_text.delete(0, tk.END)


first_window = tk.Tk()
first_window.title('Codificatore MdT')
first_window.geometry('250x300')
first_window.resizable(width=False, height=False)
first_window.iconbitmap('Resources/icon.ico')
first_window.configure(bg='#A3A3F7')

state_label = tk.Label(first_window, text='Inserisci il numero di stati della MdT:', font=('', '8', 'bold'))
state_label.configure(bg='#A3A3F7')
state_label.pack(pady=(20, 5))

state_text = tk.Entry(first_window, text="Numero di stati", font=('', '8', ''), width='36')
state_text.pack()

character_label = tk.Label(first_window, text='Inserisci i caratteri gestiti dalla MdT:', font=('', '8', 'bold'))
character_label.configure(bg='#A3A3F7')
character_label.pack(pady=(20, 5))

character_text = tk.Entry(first_window, text="Numero di caratteri", font=('', '8', ''), width='36')
character_text.pack()

bottom_frame = tk.Frame()
bottom_frame.configure(bg='#A3A3F7')
bottom_frame.pack()

enter_button = tk.Button(bottom_frame, text='Invio', command=enter_pressed)
enter_button.pack(side=tk.LEFT, padx=(10, 10), pady=(60, 60))

reset_button = tk.Button(bottom_frame, text='Reset', command=reset_pressed)
reset_button.pack(side=tk.RIGHT, padx=(10, 10), pady=(60, 60))

first_window.mainloop()
