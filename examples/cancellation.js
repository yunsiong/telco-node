const telco = require('..');

async function main() {
  const cancellable = new telco.Cancellable();

  setTimeout(() => {
    console.log('Cancelling');
    cancellable.cancel();
  }, 2000);

  const device = await telco.getDevice('xyz', { timeout: 10000 }, cancellable);
  console.log('[*] Device:', device);
}

main()
  .catch(e => {
    console.error(e);
  });
