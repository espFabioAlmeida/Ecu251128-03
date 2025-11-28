# Ecu251128-02
Projeto Automasensor: Ecu251128-03

# Entradas Digitais
IN1: Entrada Segurança <br>
IN2: Entrada Acionamento <br>
IN3: Entrada RPM (Não utilizada por enquanto) <br>
IN4: Home do Acelerador <br>
IN5: Fim de Curso do Acelerador <br>

# Relés
RELE1: SAÍDA 1 <br>
RELE2: SAÍDA 2 <br>
RELE3: Saída Horário (Avanço) do Motor <br>
RELE4: Saída Anti-Horário (Recuo) do Motor <br>

# Escopo
Projeto feito com a placa CPA-02 V1 <br>
A placa monitora a entrada de segurança, com ela desligada deve ficar tudo desligado e a entrada acionamento ignorada. <br>
Com a segurança ativada a placa monitora a entrada acionamento. Quando acionada aciona a SAÍDA 1 em retenção. E após 5 segundos aciona a SAÍDA 2, essa saída fica aciona por um tempo fixo que será calibrando em campo, por enquanto 3 segundos. Após o tempo se esgotar a SAÍDA 2 é desligada e a placa aciona o motor em AVANÇO até atingir o fim de curso. <br>
Caso a entrada de acionamento desligue a placa deve retornar para HOME e as saídas 1 e 2 desligam. <br>
Caso a entrada de segurança desligue no meio do processo as saídas 1 e 2 desligam e a placa retorna para HOME. Porém caso retorne, é necessário um novo pulso no acionamento.
