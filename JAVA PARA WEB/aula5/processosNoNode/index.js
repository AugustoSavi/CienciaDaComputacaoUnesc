const saida = {};

saida.cpuUsage = process.cpuUsage()
saida.memoryUsage = process.memoryUsage()
saida.cwd = process.cwd()
saida.argv = process.argv
saida.env = process.env

console.log(saida)

process.exit(1)