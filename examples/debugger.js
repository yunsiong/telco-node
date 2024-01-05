const telco = require('..');

const processName = process.argv[2];

const source = `
setInterval(() => {
  send(1337);
}, 1000)
`;

async function main() {
  const session = await telco.attach(processName);

  const script = await session.createScript(source, { runtime: 'v8' });
  await script.enableDebugger();
  script.message.connect(message => {
    console.log('[*] Message:', message);
  });
  await script.load();
  console.log('[*] Script loaded');
}

main()
  .catch(e => {
    console.error(e);
  });
